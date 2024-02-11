#include <stdio.h>
#include <math.h>
#include "my_mat.h"


void scanTheMatrix(int mat[LENGTH][LENGTH]){
	int count=0;
	int flag= TRUE;
    for(int i=0; i<LENGTH && (flag==TRUE) ; i++){
        for(int j=0; j<LENGTH && (flag==TRUE) ; j++){
          if ((scanf("%d",&mat[i][j])) == 1){
				count++;
		  }
			if (count == (LENGTH*LENGTH)){
				flag= FALSE;	
				//printf("choose function\n");			
			}
        }
    }
	//printf("scan");
}

void printMat(int A [LENGTH][LENGTH]){
	for(int i=0; i<LENGTH ; i++){
        for(int j=0; j<LENGTH ; j++){
       		 printf("%d ", A[i][j]);
        }
		printf("\n");
    }
}

void isPath(int A [LENGTH][LENGTH],int i,int j){
	if (A[i][j] != 0){
		printf("True\n");
	}
	else{
		printf("False\n");
	}
}

/*Using dinamic programing with Floyd–Warshall_algorithm*/	
void dinamicPrograming(int mat [LENGTH][LENGTH],int i,int j) {
	for(int k=0;k<LENGTH;k++){
		for(int i=0;i<LENGTH;i++){
			for(int j=0;j<LENGTH;j++){
				if(i==j){
				}
				else if (mat[i][k]==0 || mat[k][j]==0){
				}
				else{
					if(mat[i][j] == 0){
						mat[i][j] = mat[i][k]+mat[k][j];
					}
					else if(mat[i][j] > mat[i][k]+mat[k][j]){
						mat[i][j] = mat[i][k]+mat[k][j];
					}
				}
			}
		}	
	}	
}

void shortest(int mat[LENGTH][LENGTH],int i,int j){
    dinamicPrograming(mat, i, j);
	if(mat[i][j] == 0){
		printf("-1\n");
	}
	else{
		printf("%d\n",mat[i][j]);
	}
}