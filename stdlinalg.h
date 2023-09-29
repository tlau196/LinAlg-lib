/* Textbook Matrix functions */

#ifndef STDLINALG_H
#define STDLINALG_H

#include "matrix.h"

// Textbook Matrix Multiplication
struct fMatrix fMatrixMult(struct fMatrix* A, struct fMatrix* B){
    int i, j, k;
    struct fMatrix C = fMatrixInit(A->m, B->n);
    for(i = 0; i < A->m; i++){
        for(j = 0; j < B->n; j++){
            for(k = 0; k < A->n; k++){
                C.matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
        }
    }
    return C;
}

struct iMatrix iMatrixMult(struct iMatrix* A, struct iMatrix* B){
    int i, j, k;
    struct iMatrix C = iMatrixInit(A->m, B->n);
    for(i = 0; i < A->m; i++){
        for(j = 0; j < B->n; j++){
            for(k = 0; k < A->n; k++){
                C.matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
        }
    }
    return C;
}

#define stdMult(A, B)                   \
    _Generic((A),                       \
    struct fMatrix*: fMatrixMult,       \
    struct iMatrix*: iMatrixMult)       \
    (A, B)

// Divide and Conquer Matrix Multiplication
// Note input matrixes must be square
struct fMatrix fMatrixDivConqMult(struct fMatrix* A, struct fMatrix* B, struct fMatrix* C, struct matCoord head_ptr, struct matCoord tail_ptr){
    if (head_ptr.i == tail_ptr.i + 1){
        C->matrix[head_ptr.i][head_ptr.j] = A->matrix[head_ptr.i][head_ptr.j] * B->matrix[head_ptr.i][head_ptr.j]
            + A->matrix[head_ptr.i+1][head_ptr.j] * B->matrix[head_ptr.i][head_ptr.j+1];
    }
}

// Transposition
struct fMatrix fTranspose(struct fMatrix* A){
    int i, j;
    float temp;
    struct fMatrix A_trans = fMatrixInit(A->n, A->m);

    for(i = 0; i < A->m; i++){
        for(j = 0; j < A->n; j++){
            A_trans.matrix[j][i] = A->matrix[i][j];
        }
    }
    return A_trans;
}

struct iMatrix iTranspose(struct iMatrix* A){
    int i, j;
    float temp;
    struct iMatrix A_trans = iMatrixInit(A->n, A->m);

    for(i = 0; i < A->m; i++){
        for(j = 0; j < A->n; j++){
            A_trans.matrix[j][i] = A->matrix[i][j];
        }
    }
    return A_trans;
}

#define transpose(A)                    \
    _Generic((A),                       \
    struct iMatrix*: iTranspose,        \
    struct fMatrix*: fTranspose)        \
    (A)

// In-Place matrix transpose
//
// NOT YET IMPLEMENTED

#endif
