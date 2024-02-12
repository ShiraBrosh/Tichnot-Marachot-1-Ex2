#include "my_mat.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_PRODUCTS 5  // Number of products   
#define MAX_CAPACITY 20 // Max capacity of bag

/* Return the maximum of two values */
#define MAX(x, y) ((x) > (y) ? (x) : (y))

/* This function creates the table and enters selected_bool the selected items and returns the max value of all the products */
int chooseItems(int weights[], int values[], int selected_bool[]) {
    /* Create the table */
    int table[NUM_PRODUCTS + 1][MAX_CAPACITY + 1];
    for (int i = 0; i <= NUM_PRODUCTS; i++) {
        for (int j = 0; j <= MAX_CAPACITY; j++) {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else if (weights[i - 1] <= j)
                table[i][j] = MAX(table[i - 1][j], values[i - 1] + table[i - 1][j - weights[i - 1]]);
            else
                table[i][j] = table[i - 1][j];
        }
    }
    int x = NUM_PRODUCTS;
    int y = MAX_CAPACITY;
    while (x > 0 && y > 0) {
        selected_bool[x - 1] = (table[x][y] == table[x - 1][y]) ? 0 : 1;
        x -= 1;
        if (selected_bool[x] == 1)
            y -= weights[x];
    }
    return table[NUM_PRODUCTS][MAX_CAPACITY];
}

int main() {
    int selected_bool[NUM_PRODUCTS];
    char products[NUM_PRODUCTS];
    int values[NUM_PRODUCTS] = {0};
    int weights[NUM_PRODUCTS] = {0};
    // Insert input of products, values, and weights
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        scanf(" %c", &products[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }
    // print results
    int maxProfit = chooseItems(weights, values, selected_bool);
    printf("Maximum profit: %d\n", maxProfit);
    printf("Selected items:");
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        if (selected_bool[i] == 1)
            printf(" %c", products[i]);
    }

    int result[NUM_PRODUCTS]; // Define result array
    for (int i = 0; i < NUM_PRODUCTS; ++i) {
        result[i] = selected_bool[i];
    }

    return 0;
}