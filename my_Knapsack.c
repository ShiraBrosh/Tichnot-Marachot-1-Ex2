#include "my_mat.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_PRODUCTS 5  
#define MAX_CAPACITY 20 

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int chooseItems(int weights[], int values[], int result[]) {
    int mat[NUM_PRODUCTS + 1][MAX_CAPACITY + 1];
    
    for (int i = 0; i <= NUM_PRODUCTS; i++)
        for (int j = 0; j <= MAX_CAPACITY; j++)
            mat[i][j] = (i == 0 || j == 0) ? 0 : (weights[i - 1] <= j) ? MAX(mat[i - 1][j], values[i - 1] + mat[i - 1][j - weights[i - 1]]) : mat[i - 1][j];
    
    int x = NUM_PRODUCTS, y = MAX_CAPACITY;
    while (x > 0 && y > 0)
        result[--x] = (mat[x + 1][y] == mat[x][y]) ? 0 : (y -= (result[x] = 1)) ? weights[x] : 0;
    
    return mat[NUM_PRODUCTS][MAX_CAPACITY];
}

int main() {
    char products[NUM_PRODUCTS];
    int values[NUM_PRODUCTS];
    int weights[NUM_PRODUCTS];
    
    int result[NUM_PRODUCTS] = {0};
    
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        scanf(" %c %d %d", &products[i], &values[i], &weights[i]);
    }
    
    int maxProfit = chooseItems(weights, values, result);
    
    printf("Maximum profit: %d\n", maxProfit);
    printf("Selected items:");
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        if (result[i]) printf(" %c", products[i]);
    }

    return 0;
}

