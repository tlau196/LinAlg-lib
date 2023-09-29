#ifndef MATRIX_H
#define MATRIX_H
#include <stdlib.h>
#include <stdio.h>

// float matrix and int matrix data type initialisation.

struct fMatrix{
    float** matrix;
    int m;
    int n;
};

struct iMatrix{
    int** matrix;
    int m;
    int n;
};

float** newFloatMatrix(int m, int n){
    int i;
    float** mat = (float**)malloc((m) * sizeof(float*));
    for  (i = 0; i < m; i++){
        mat[i] = (float*)malloc(n * sizeof(float));
    }
    return mat;
}

int** newIntMatrix(int m, int n){
    int i;
    int** mat = (int**)malloc(m * sizeof(int*));
    for (i = 0; i < m; i++){
        mat[i] = (int*)malloc(n * sizeof(int));
    }
    return mat;
}

struct fMatrix fMatrixInit(int m, int n){
    float** matrix = newFloatMatrix(m ,n);
    struct fMatrix fMat;
    fMat.matrix = matrix;
    fMat.m = m;
    fMat.n = n;
    return fMat;
}

struct iMatrix iMatrixInit(int m, int  n){
    int** matrix = newIntMatrix(m, n);
    struct iMatrix iMat;
    iMat.matrix = matrix;
    iMat.m = m;
    iMat.n = n;
    return iMat;
}

// Matrix Vector Addressing
struct matCoord{
    int i;
    int j;
};

// IO functions

void printIntMatrix(struct iMatrix mat){
    int i, j;
    for(i = 0; i < mat.m; i++){
        for(j = 0; j < mat.n; j++){
            printf("%d ", mat.matrix[i][j]);
        }
        printf("\n");
    }
}

void printFloatMatrix(struct fMatrix mat){
    int i, j;
    for(i = 0; i < mat.m; i++){
            printf("%f ", mat.matrix[i][j]);
        }
        printf("\n");
    }
}

#define printMatrix(mat)                    \
        _Generic((mat),                     \
        struct iMatrix: printIntMatrix,              \
        struct fMatrix: printFloatMatrix)          \
        (mat)

// Garbage Collection

void free_fMatrix(struct fMatrix* mat){
    int i;
    for(i = 0; i < mat->m; i++){
        free(mat->matrix[i]);
    }
    free(mat->matrix);
}

void free_iMatrix(struct iMatrix* mat){
    int i;
    for(i = 0; i < mat->m; i++){
        free(mat->matrix[i]);
    }
    free(mat->matrix);
}

#define freeMatrix(mat)             \
    _Generic((mat),                 \
    struct iMatrix*: free_iMatrix,    \
    struct fMatrix*: free_fMatrix)    \
    (mat)

int isSquare_fMatrix(struct fMatrix* mat){
    if (mat->m == mat->n){
        return 1;
    }
    else {
        return 0;
    }
}

int isSquare_iMatrix(struct iMatrix* mat){
    if (mat->m == mat->n){
        return 1;
    }
    else {
        return 0;
    }
}

#define isSquare(mat)       \
    _Generic((mat),         \
    struct iMatrix*: isSquare_iMatrix       \
    struct fMatrix*: isSquare_fMatrix)       \
    (mat)

// Size diff
int* dimDiff_fMatrix(struct fMatrix* A, struct fMatrix*B){
    int m, n;
    int* mn = (int*)malloc(2 * sizeof(int));
    m = A->m - B->n;
    n = A->n - B->n;
    mn[0] = m;
    mn[1] = n;
    return mn;
}

#endif
