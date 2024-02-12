#include "my_mat.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_PRODUCTS 5  // Number of products   
#define MAX_CAPACITY 20 // Max capacity of bag

// Return the maximum of two values 
#define MAX(x, y) ((x) > (y) ? (x) : (y))


 // This function creates the matrix and enters result the selected items and returns the max value of all the products 

int chooseItems(int weights[], int values[], int result[]) {
    // Create a matrix to store the maximum values
    int mat[NUM_PRODUCTS + 1][MAX_CAPACITY + 1];
    
    // Fill the matrix using dynamic programming approach
    for (int i = 0; i <= NUM_PRODUCTS; i++) {
        for (int j = 0; j <= MAX_CAPACITY; j++) {
            // Base case: if no products or capacity is 0, profit is 0
            mat[i][j] = (i == 0 || j == 0) ? 0 : 
                        // If weight of current product fits in current capacity
                        (weights[i - 1] <= j) ? 
                            // Take the maximum value either by considering or not considering the current product
                            MAX(mat[i - 1][j], values[i - 1] + mat[i - 1][j - weights[i - 1]]) : 
                            // If weight of current product exceeds current capacity, choose the previous value
                            mat[i - 1][j];
        }
    }
    
    // Traceback to find the selected items
    int x = NUM_PRODUCTS, y = MAX_CAPACITY;
    while (x > 0 && y > 0) {
        // If the value at the current cell is equal to the value in the cell above, the item wasn't selected
        result[--x] = (mat[x + 1][y] == mat[x][y]) ? 0 : 
                      // Otherwise, the item was selected, mark it as 1
                      (y -= (result[x] = 1)) ? weights[x] : 0;
    }
    
    // Return the maximum profit achieved
    return mat[NUM_PRODUCTS][MAX_CAPACITY];
}

int main() {
    // Initialize arrays to store product names, values, and weights
    char products[NUM_PRODUCTS];
    int values[NUM_PRODUCTS];
    int weights[NUM_PRODUCTS];
    
    // Initialize result array with zeros
    int result[NUM_PRODUCTS] = {0};
    
    // Input product names, values, and weights
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        scanf(" %c %d %d", &products[i], &values[i], &weights[i]);
    }
    
    // Find the maximum profit and selected items
    int maxProfit = chooseItems(weights, values, result);
    
    // Output the maximum profit
    printf("Maximum profit: %d\n", maxProfit);
    
    // Output the selected items
    printf("Selected items:");
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        if (result[i]) printf(" %c", products[i]);
    }

    return 0;
}
