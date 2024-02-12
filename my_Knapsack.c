#include <stdio.h>

#define MAX_WEIGHT 20           // Maximum weight
#define NUM_ITEMS 5             // Number of items
# define TRUE 1
# define FALSE 0

int knapSack(int weights[MAX_WEIGHT], int values[NUM_ITEMS], int selected[NUM_ITEMS]);

int main() {
    char item_names[NUM_ITEMS +1];           // one more its for \0 
    int item_values[NUM_ITEMS] = {0};
    int item_weights[MAX_WEIGHT] = {0};

    for (size_t i = 0; i < NUM_ITEMS; i++) {
        scanf("%s %d %d", item_names[i], &item_values[i], &item_weights[i]);   // scan the values for the items
        if (i < NUM_ITEMS - 1) {
            scanf(" ");
        }
    }

    int result[NUM_ITEMS] = {FALSE}; 

    int max_profit = knapSack(item_weights, item_values, result);

    printf("Maximum profit: %d\n", max_profit);
    printf("Selected items:");

    for (size_t i = 0; i < NUM_ITEMS; i++) {
        if (result[i] == TRUE) {                    //this item in the bag
            printf(" %s", item_names[i]);
        }
    }

    return 0;
}

int knapSack(int weights[MAX_WEIGHT], int values[NUM_ITEMS], int selected[NUM_ITEMS]) {
    int matrix[NUM_ITEMS + 1][MAX_WEIGHT + 1];      // one more its for line zero

    for (int i = 0; i <= NUM_ITEMS; i++) {       // Initialize the matrix with 0
        for (int j = 0; j <= MAX_WEIGHT; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 1; i <= NUM_ITEMS; i++) {       // make the dynamic programming
        for (int j = 1; j <= MAX_WEIGHT; j++) {
            if (weights[i - 1] <= j) {
                if (values[i - 1] + matrix[i - 1][j - weights[i - 1]] > matrix[i - 1][j]) {
                    matrix[i][j] = values[i - 1] + matrix[i - 1][j - weights[i - 1]];
                } 
                else {
                    matrix[i][j] = matrix[i - 1][j];
                }
            } 
            else {
                matrix[i][j] = matrix[i - 1][j];
            }
        }
    }

    int total_weight = MAX_WEIGHT;
    for (size_t i = NUM_ITEMS; i > 0; i--) {
        if (matrix[i][total_weight] != matrix[i - 1][total_weight]) {
            selected[i - 1] = TRUE;
            total_weight -= weights[i - 1];        
        }
    }

    return matrix[NUM_ITEMS][MAX_WEIGHT];
}