#include "test_matrix.h"

//
#define RUN_TEST(test) \
    if (!(test())) { \
        printf("%s failed\n", #test); \
        success = 0; \
    } else { \
        printf("%s passed\n", #test); \
    }

int run_matrix_tests(){
    int success = 1;

    RUN_TEST(test_matrix_constructor);

    return success ? 0 : 1;
};

int test_matrix_constructor(){
    // matrix declaration
    matrix_t m;

    // construction of a matrix of size 2,3
    if (matrix_construct(&m, 2, 3) != MATRIX_SUCCESS)
        return 0;

    // size check
    if (m.rows != 2 || m.cols != 3)
        return 0;

    // 0 initialization check
    for (size_t i = 0; i < m.rows; i++) {
        for (size_t j = 0; j < m.cols; j++) {
            if (matrix_get(&m, i, j) != 0.0)
                return 0;
        }
    }

    matrix_free(&m);
    return 1;
};

int test_matrix_free();

int test_matrix_get();

int test_matrix_get_macro();

int test_matrix_set();

int test_matrix_copy();

int test_matrix_clone();

int test_matrix_add();

int test_matrix_scale();

int test_matrix_multiply();
