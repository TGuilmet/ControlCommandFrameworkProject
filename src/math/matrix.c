#include <matrix.h>

//Constructor
int matrix_construct(matrix_t *m, size_t rows, size_t cols){
    

};

//Descructor
void matrix_free(matrix_t *m){

};

// Copy a matrix but size should be equal
// R should always be different from m
int matrix_copy(matrix_t *R, const matrix_t *m){

};

// Copy and reallocate if the size are different.
//R should always be different from m
int matrix_clone(matrix_t *R, const matrix_t *m){

};

// Acces to element (i,j)
double matrix_get(const matrix_t *m, size_t i, size_t j){

};

// Set element (i,j)
void matrix_set(matrix_t *m, size_t i, size_t j, double value){

};

// Addition of matrices
// R should always be different from A and B
int matrix_add(matrix_t *R, const matrix_t *A, const matrix_t *B){

};

// Multiply by a scalar
void matrix_scale(matrix_t *m, double k){

};

//Multiply two matrices
// R should always be different from A and B
int matrix_multiply(matrix_t *R, const matrix_t *A, const matrix_t *B){

};
