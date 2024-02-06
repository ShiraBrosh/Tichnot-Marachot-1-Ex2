// #include <stdio.h>
// #include<stdbool.h>
// #include "my_mat.h"
// #define True 1
// #define False 0

// void getNumbers(int A[LENGTH][LENGTH]){
// 	int count = 0;	
// 	for(int i=0;i<LENGTH;i++){
// 		for(int j=0;j<LENGTH;j++){
// 			if(count <= LENGTH*LENGTH){
// 			 if((scanf(" %d",&A[i][j])) == 1) count++;
// 			}
// 		}
// 	}
// 	printf("THE MATRIX IS FULL");
// }

// int isPath(int A [LENGTH][LENGTH],int i,int j){
// 	if (A[i][j]!=0){
// 		return True;
// 	}
// 	else{
// 		return False;
// 	}
// }

// void dinamic_programing(int A [LENGTH][LENGTH],int i, int j){
// 	for(int k=0;k<LENGTH;k++){
// 		for(int i=0;i<LENGTH;i++){
// 			for(int j=0;j<LENGTH;j++){
// 				if(i==j){
// 				}
// 				else if (A[i][k]==0 || A[k][j]==0){
// 				}
// 				else{
// 					if(A[i][j] == 0){
// 						A[i][j] = A[i][k]+A[k][j];
// 					}
// 					else if(A[i][j] > A[i][k]+A[k][j]){
// 						A[i][j] = A[i][k]+A[k][j];
// 					}
// 				}
// 			}
// 		}	
// 	}	
// }

// void shortest(int A [LENGTH][LENGTH],int i,int j){
// 	dinamic_programing(A,i,j);
// 	if(A[i][j] == 0){
// 		printf("-1\n");
// 	}
// 	else{
	
// 		printf("%d\n",A[i][j]);
// 	}
// }

#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"

#define True 1
#define False 0
#define LENGTH 10 // Assuming a predefined value for LENGTH

void getNumbers(int A[LENGTH][LENGTH]) {
    int count = 0;	
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            if (count < LENGTH * LENGTH) {
                if (scanf("%d", &A[i][j]) == 1) 
                    count++;
            }
        }
    }
    printf("THE MATRIX IS FULL");
}

bool isPath(int A[LENGTH][LENGTH], int i, int j) {
    return A[i][j] != 0;
}

void dynamic_programming(int A[LENGTH][LENGTH], int i, int j) {
    for (int k = 0; k < LENGTH; k++) {
        for (int i = 0; i < LENGTH; i++) {
            for (int j = 0; j < LENGTH; j++) {
                if (i == j) {
                    continue;
                }
                else if (A[i][k] == 0 || A[k][j] == 0) {
                    continue;
                }
                else {
                    if (A[i][j] == 0) {
                        A[i][j] = A[i][k] + A[k][j];
                    }
                    else if (A[i][j] > A[i][k] + A[k][j]) {
                        A[i][j] = A[i][k] + A[k][j];
                    }
                }
            }
        }
    }
}

void shortest(int A[LENGTH][LENGTH], int i, int j) {
    dynamic_programming(A, i, j);
    if (A[i][j] == 0) {
        printf("-1\n");
    }
    else {
        printf("%d\n", A[i][j]);
    }
}
