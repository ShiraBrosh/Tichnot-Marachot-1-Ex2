#define LENGTH 2
#ifndef MY_MAT_H
#include <stdbool.h>
/*'A'*/
void getNumbers(int A[LENGTH][LENGTH]);

/*'B'*/
bool isPath(int A[LENGTH][LENGTH], int i, int j);

/*'C'*/
void shortest(int A[LENGTH][LENGTH], int i, int j);

#endif
