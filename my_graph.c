#include "my_mat.h"
#include <stdio.h>

int main (){
    int mat[LENGTH][LENGTH];
    char choice = 'H'; // Initialize choice to any non-'D' value
	int i ,j ;

    while(choice != 'D') {
        //printf("Choose function (A/B/C/D): ");
        scanf(" %c", &choice); // Add a space before %c to consume any leading whitespace

        switch (choice) {
            case 'A':
                scanTheMatrix(mat);
                break;
            case 'B':
                scanf("%d %d", &i, &j);
                isPath(mat, i, j);
                break;
            case 'C':
                scanf("%d %d", &i, &j);
                shortest(mat, i, j);
                break;
            case 'D':
                break; // Exit the loop
            default:
                //printf("Invalid choice. Please enter A, B, C, or D.\n");
                break;
        }
    }

    return 0;
}