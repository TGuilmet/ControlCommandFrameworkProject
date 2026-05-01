#ifndef MATRIX_H
#define MATRIX_H

#include <common.h>

typedef struct {
    double *data;
    size_t rows;
    size_t cols;
} matrix_t;

//Constructeur
void construct_matrix(matrix_t *m);

// Acces to element (i,j)
double matrix_get(const matrix_t *m, size_t i, size_t j);

// Set element (i,j)
void matrix_set(matrix_t *m, size_t i, size_t j, double value);

// Addition of matrices
int add_matrix(matrix_t *a, const matrix_t *b);

// Multiply by a scalar
void scale_matrix(matrix_t *m, double k);

//Multiply two matrices
int multiply(matrix_t *A, matrix_t *B);

#endif
