#ifndef MATRIX_H
#define MATRIX_H

#include <common.h>

#define MATRIX_SUCCESS 0
#define MATRIX_ERROR -1

typedef struct {
    double *data;
    size_t rows;
    size_t cols;
} matrix_t;

//Constructor
int matrix_construct(matrix_t *m, size_t rows, size_t cols);

//Descructor
void matrix_free(matrix_t *m);

// Copy
void matrix_copy(matrix_t*R, const matrix_t *m);

// Acces to element (i,j)
double matrix_get(const matrix_t *m, size_t i, size_t j);

// Set element (i,j)
void matrix_set(matrix_t *m, size_t i, size_t j, double value);

// Addition of matrices
int matrix_add(matrix_t *R, const matrix_t *A, const matrix_t *B);

// Multiply by a scalar
void matrix_scale(matrix_t *m, double k);

//Multiply two matrices
int matrix_multiply(matrix_t *R, const matrix_t *A, const matrix_t *B);

#endif
