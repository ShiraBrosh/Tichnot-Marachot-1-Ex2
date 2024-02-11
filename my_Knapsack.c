#include <stdio.h>

#define MAX_WEIGHT 20
#define MAX_ITEMS 5


#define MaxWeight 20 // Maximum weight
#define Items 5 // Number of items
#define true 1
#define false 0
#define MaxStringLength 20 // Max length for a name of an item

// Function to maximize the total value within the weight constraint
int knapSack(int weights[], int values[], int selected_bool[]) {
    int i, w;
    int K[MAX_ITEMS + 1][MAX_WEIGHT + 1];

    // Build table K[][] in bottom-up manner
    for (i = 0; i <= MAX_ITEMS; i++) {
        for (w = 0; w <= MAX_WEIGHT; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = (values[i - 1] + K[i - 1][w - weights[i - 1]]) > K[i - 1][w] ? 
                          (values[i - 1] + K[i - 1][w - weights[i - 1]]) : K[i - 1][w];
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // Fill selected_bool[] to track selected items
    w = MAX_WEIGHT;
    for (i = MAX_ITEMS; i > 0 && w > 0; i--) {
        if (K[i][w] != K[i - 1][w]) {
            selected_bool[i - 1] = 1;
            w = w - weights[i - 1];
        }
    }

    // Return the maximum value achieved
    return K[MAX_ITEMS][MAX_WEIGHT];
}
int main(){
    char items[Items][MaxStringLength + 1]; // The + 1 is for /0 at the end of the string
    int values[Items] = {0};
    int weights[] = {0};

    // Get the values for the items
    for(size_t i = 0; i < Items; i++){
        scanf("%s %d %d", items[i], &values[i], &weights[i]);

        if(i < Items - 1){
            scanf(" ");
        }
    }

    int result[Items] = {0}; // The result array. It will indicate if we took the item

    // Finding the maximum profit possible
    int MaxProfit = knapSack(weights, values, result);

    // Printing the information
    printf("Maximum profit: %d\n", MaxProfit);
    printf("Selected items:");

    // Printing the selected items
    for(size_t i = 0; i < Items; i++){
        if(result[i] == true){
            printf(" %s", items[i]);
        }
    }

    return 0;
}
