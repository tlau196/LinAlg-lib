#include <stdio.h>
#include "linearlib.h"

int main(){
    struct fMatrix A = fMatrixInit(2, 3);
    A.matrix[0][0] = 5;
    A.matrix[0][1] = 3;
    A.matrix[1][0] = 6;
    A.matrix[1][1] = 2;
    A.matrix[0][2] = 4;
    A.matrix[1][2] = 9;

    struct fMatrix B = fMatrixInit(2, 2);
    B.matrix[0][0] = 8;
    B.matrix[0][1] = 5;
    B.matrix[1][0] = 3;
    B.matrix[1][1] = 2;

    printf("A =\n");
    printMatrix(A);
    printf("B =\n");
    printMatrix(B);
    
    struct fMatrix A_transpose = transpose(&A);
    printf("A^T = \n");
    printMatrix(A_transpose);
    //printf("A . B =\n");
    //printMatrix(stdMult(&A, &B));
    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&A_transpose);
    return 0;
}
