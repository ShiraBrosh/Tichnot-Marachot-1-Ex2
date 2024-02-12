#include "my_mat.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_PRODUCTS 5  // Number of products   
#define MAX_CAPACITY 20 // Max capacity of bag

/* Return the maximum of two values */
#define MAX(x, y) ((x) > (y) ? (x) : (y))

/* This function creates the table and enters result the selected items and returns the max value of all the products */
int chooseItems(int weights[], int values[], int result[]) {
    int table[NUM_PRODUCTS + 1][MAX_CAPACITY + 1];
    
    for (int i = 0; i <= NUM_PRODUCTS; i++)
        for (int j = 0; j <= MAX_CAPACITY; j++)
            table[i][j] = (i == 0 || j == 0) ? 0 : (weights[i - 1] <= j) ? MAX(table[i - 1][j], values[i - 1] + table[i - 1][j - weights[i - 1]]) : table[i - 1][j];
    
    int x = NUM_PRODUCTS, y = MAX_CAPACITY;
    
    while (x > 0 && y > 0)
        result[--x] = (table[x + 1][y] == table[x][y]) ? 0 : (y -= (result[x] = 1)) ? weights[x] : 0;
    
    return table[NUM_PRODUCTS][MAX_CAPACITY];
}

int main() {
    int result[NUM_PRODUCTS];
    char products[NUM_PRODUCTS];
    int values[NUM_PRODUCTS] = {0};
    int weights[NUM_PRODUCTS] = {0};
    
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        scanf(" %c", &products[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }
    
    int maxProfit = chooseItems(weights, values, result);
    printf("Maximum profit: %d\n", maxProfit);
    printf("Selected items:");
    
    for (int i = 0; i < NUM_PRODUCTS; i++)
        if (result[i]) printf(" %c", products[i]);

    return 0;
}
