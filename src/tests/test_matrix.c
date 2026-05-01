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
    RUN_TEST(test_matrix_free);
    RUN_TEST(test_matrix_get);
    RUN_TEST(test_matrix_set); // TODO
    RUN_TEST(test_matrix_macro);

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
            if (MAT(&m, i, j) != 0.0)
                return 0;
        }
    }

    matrix_free(&m);
    return 1;
};

int test_matrix_free(){

    matrix_t m;

    if ( matrix_construct(&m, 3,3) != MATRIX_SUCCESS)
        return 0;
    
    matrix_set(&m,1,1,42.0);

    matrix_free(&m);

    if (m.data !=NULL) return 0;
    if (m.rows !=0) return 0;
    if (m.cols !=0) return 0;

    return 1;
};

int test_matrix_get(){
    
    matrix_t m;

    if (matrix_construct(&m, 2, 2) != MATRIX_SUCCESS)
        return 0;

    matrix_set(&m, 0, 1, 3.14);

    double val1 = 0.0;
    double val2 = 0.0;
    double val3 = 0.0;

    int succes1 = matrix_get(&m, 0, 1, &val1);
    int succes2 = matrix_get(&m, 4, 2, &val2);
    int succes3 = matrix_get(&m, 0, 2+1, &val3);

    matrix_free(&m);

    return (val1 == 3.14 && succes1 && val2 == 0.0 && !(succes2) && val3 == 0.0 && !(succes3));

};

int test_matrix_macro(){
    matrix_t m1;
    matrix_t m2;

    if (matrix_construct(&m1, 2, 2) != MATRIX_SUCCESS)
        return 0;

    if (matrix_construct(&m2, 2, 2) != MATRIX_SUCCESS)
        return 0;

    MAT(&m1, 1, 0) = 7.0;
    matrix_set(&m2, 1, 0, 7.0);

    double val1 = MAT(&m1, 1, 0);
    double val2 = 0.0;
    matrix_get(&m2, 1, 0, &val2);

    matrix_free(&m1);matrix_free(&m2);

    return (val1 == val2);
};

int test_matrix_set(){

    matrix_t m;

    if (matrix_construct(&m, 2, 2) != MATRIX_SUCCESS)
        return 0;

    if (matrix_set(&m, 1, 1, 9.0) != MATRIX_SUCCESS)
        return 0;

    double val = 0.0;
    int get_succes = matrix_get(&m, 1, 1, &val);

    matrix_free(&m);

    return (val == 9.0 && get_succes);
};

int test_matrix_copy();

int test_matrix_clone();

int test_matrix_add();

int test_matrix_scale();

int test_matrix_multiply();
