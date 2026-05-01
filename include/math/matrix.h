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
int construct_matrix(matrix_t *m, size_t rows, size_t cols);

//Descructor
void free_matrix(matrix_t *m);

// Copy
void copy_matrix(matrix_t*R, matrix_t *m);

// Acces to element (i,j)
double get_value_matrix(const matrix_t *m, size_t i, size_t j);

// Set element (i,j)
void set_value_matrix(matrix_t *m, size_t i, size_t j, double value);

// Addition of matrices
int add_matrix(matrix_t *R, matrix_t *A, const matrix_t *B);

// Multiply by a scalar
void scale_matrix(matrix_t *m, double k);

//Multiply two matrices
int multiply(matrix_t *R, matrix_t *A, matrix_t *B);

#endif
