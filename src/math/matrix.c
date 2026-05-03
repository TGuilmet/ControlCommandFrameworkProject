#include "math/matrix.h"
#include "common.h"

//Constructor
int matrix_construct(matrix_t *m, size_t rows, size_t cols){

        // if empty pointer or rows or cols are 0, return an error
        if (m == NULL || rows == 0 || cols == 0)
            return MATRIX_ERROR;

        // default structure with NULL pointer in data
        // if calloc fails
        m->rows = rows;
        m->cols = cols;
        m->data = NULL;

        //initialize with zeros
        m->data = calloc(rows * cols, sizeof(double));

        if (m->data == NULL)
            return MATRIX_ERROR;

    return MATRIX_SUCCESS;
};

//Descructor
void matrix_free(matrix_t *m){

    // check if m is not a NULL pointer
    if (m==NULL)
        return;
        
    // free memory
    free(m->data);

    // default structure for empty matrix
    m->data = NULL;
    m->rows = 0;
    m->cols = 0;
};

// Copy a matrix but size should be equal
// R should always be different from m

int matrix_copy(matrix_t *R, const matrix_t *m){
    // Check if not NULL pointer
    if (R == NULL || m== NULL)
        return MATRIX_ERROR;

    //Check if R and m are the same size
    if (R->cols != m->cols || R->rows != m->rows)
        return MATRIX_ERROR;
    
    // Replace every value of R by values of m
    // Maybe R-> data = m->data ??
    for (size_t i=0; i<(m->rows); i++)
        for(size_t j=0; j<(m->cols); j++)
            MAT(R,i,j)=MAT(m,i,j);
    
    return MATRIX_SUCCESS;
};

// Copy and reallocate if the size are different.
//R should always be different from m
int matrix_clone(matrix_t *R, const matrix_t *m){

    if (R == NULL || m== NULL)
        return MATRIX_ERROR;

    R->rows = m->rows;
    R->cols = m->cols;
    // Or copy (R,m)
    free(R->data);
    R->data = malloc(m->rows * m->cols * sizeof(double));
    
    for (size_t i=0; i<(m->rows); i++)
        for(size_t j=0; j<(m->cols); j++)
            MAT(R,i,j)=MAT(m,i,j);
    return MATRIX_SUCCESS;
};

// Acces to element (i,j) with check
int matrix_get(const matrix_t *m, size_t i, size_t j, double *out){

    if (m== NULL || out == NULL)
        return MATRIX_ERROR;
    
    if (i>=m->rows || j >= m->cols)
        return MATRIX_ERROR;
        
    *out = m->data[(i) * (m)->cols + (j)];

    return MATRIX_SUCCESS;
};

// Set element (i,j) with size check
int matrix_set(matrix_t *m, size_t i, size_t j, double value){

       if (m== NULL)
        return MATRIX_ERROR;
    
    if (i>=m->rows || j >= m->cols)
        return MATRIX_ERROR;
        
    m->data[(i) * (m)->cols + (j)] = value;

    return MATRIX_SUCCESS;
};

// Addition of matrices
// R should always be different from A and B
int matrix_add(matrix_t *R, const matrix_t *A, const matrix_t *B){
    
    if (R==NULL || A==NULL || B==NULL)
        return MATRIX_ERROR;

    if(A->cols != B->cols || A->rows != B->rows)
        return MATRIX_ERROR;
    size_t rows = A->rows;
    size_t cols = A-> cols;
    R->cols = cols;
    R->rows = rows;

    free(R->data);
    R->data = malloc(rows * cols * sizeof(double));

    for (size_t i=0; i<rows; i++)
        for(size_t j=0; j<cols; j++)
            MAT(R,i,j)=MAT(A,i,j)+MAT(B,i,j);

    return MATRIX_SUCCESS;
};

// Multiply by a scalar
void matrix_scale(matrix_t *m, double k){

    if(m==NULL);
        return MATRIX_ERROR;
    
    for (size_t i=0; i<(m->rows); i++)
        for(size_t j=0; j<(m->cols); j++)
            MAT(m,i,j)=k*MAT(m,i,j);
    
    return MATRIX_SUCCESS;
};

//Multiply two matrices A*B
// R should always be different from A and B
int matrix_multiply(matrix_t *R, const matrix_t *A, const matrix_t *B){

    if(A==NULL || B==NULL);
        return MATRIX_ERROR;

    
    if (A->cols != B->rows)
        return MATRIX_ERROR;

    free(R->data);
    R->data = calloc((A->rows) * (B->cols), sizeof(double));

    for (size_t i=0; i<(A->rows); i++)
        for(size_t j=0; j<(B->cols); j++)
            // R(i,j term)
                for(size_t k=0; k<(A->cols); k++)
                MAT(R,i,j)+= MAT(A,i,k)*MAT(B,k,j);
    
    return MATRIX_SUCCESS;

    
};

int matrix_transpose (matrix_t *R,const matrix_t *m){

    if(R==NULL || m==NULL)
        return MATRIX_ERROR;

    R->rows = m->cols;
    R->cols = m->rows;
    free(R->data);

    R->data = malloc(R->cols * R->rows * sizeof(double));
    for (size_t i=0; i<(m->rows); i++)
        for(size_t j=0; j<(m->cols); j++)
            MAT(R,j,i) = MAT(m,i,j);
    
    return MATRIX_SUCCESS;
}

int matrix_compare(const matrix_t *A, const matrix_t *B){

    if(A==NULL || B==NULL)
        return MATRIX_ERROR;

    if(A->rows != B->rows || A->cols != B->cols)
        return MATRIX_ERROR;

    for (size_t i = 0; i<(A->rows); i++)
        for (size_t j = 0; j<(A->cols); j++)
            if (MAT(A,i,j)!=MAT(B,i,j))
                return FALSE;
    
    return TRUE;

}
