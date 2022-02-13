#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "test_solve.h"
#include "../src/solve.h"
#include "../src/init.h"
#include "../src/helpers.h"

void test_determinant() {
    assert(determinant(NULL) == 0);
    matrix *zero = zeros(3, 2);
    assert(determinant(zero) == 0);
    double easy_arr[] = {3, 8, 4, 6};
    matrix *easy_mat = from_array(easy_arr, 2, 2);
    assert(determinant(easy_mat) == -14);
    double hard_arr[] = {6, 1, 1, 4, -2, 5, 2, 8, 7};
    matrix *hard_mat = from_array(hard_arr, 3, 3);
    assert(determinant(hard_mat) == -306);
    matrix_free(zero);
    matrix_free(easy_mat);
    matrix_free(hard_mat);
}

void test_inverse() {
    double arr[] = {3, 0, 2, 2, 0, -2, 0, 1, 1};
    matrix *mat = from_array(arr, 3, 3);
    double inverse_arr[] = {0.2, 0.2, 0, -0.2, 0.3, 1, 0.2, -0.3, 0};
    unsigned int rows = 3, cols = 3;
    matrix *eye = identity(rows);
    matrix *inverse_mat = from_array(inverse_arr, rows, cols);
    matrix *expected_mat = concat_col(eye, inverse_mat);
    matrix *result = inverse(mat);
    double tolerance = 1e-15;
    for (int i = 0; i < rows * 2; i++) {
        for (int j = 0; j < cols; j++) {
            double expected = get_value(expected_mat, i, j);
            double actual = get_value(result, i, j);
            double error = expected - actual;
            assert(error < tolerance);
        }
    }
    matrix_free(mat);
    matrix_free(result);
    matrix_free(eye);
    matrix_free(inverse_mat);
    matrix_free(expected_mat);
}

void test_row_reduction() {
    assert(row_reduction(NULL, NULL) == NULL);
    double arr_a[] = {1, 3, -2, 3, 5, 6, 2, 4, 3};
    unsigned int rows = 3, cols_a = 3, cols_b = 1;
    matrix *mat_a = from_array(arr_a, rows, cols_a);
    assert(row_reduction(mat_a, mat_a) == NULL);
    double arr_b[] = {5, 7, 8};
    matrix *mat_b = from_array(arr_b, rows, cols_b);
    matrix *final = row_reduction(mat_a, mat_b);
    assert(final != NULL);
    assert(final->rows == rows);
    assert(final->cols == cols_a + cols_b);
    double expected[] = {1, 0, 0, -15, 0, 1, 0, 8, 0, 0, 1, 2};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < final->cols; j++) {
            int index = i * final->cols + j;
            double actual = get_value(final, i, j);
            assert(expected[index] == actual);
        }
    }
    matrix_free(mat_a);
    matrix_free(mat_b);
    matrix_free(final);
}

void test_rank() {
    assert(rank(NULL) == 0);
    double arr[] = {1, 2, 1, -2, -3, 1, 3, 5, 0};
    matrix *mat = from_array(arr, 3, 3);
    assert(rank(mat) == 2);
    unsigned int n = 3;
    matrix *eye = identity(n);
    assert(rank(eye) == n);
    matrix_free(mat);
    matrix_free(eye);
}

void test_all_solve() {
    printf("Testing equation solvers...\t\t");
    test_determinant();
    test_inverse();
    test_row_reduction();
    test_rank();
    printf("Passed\n");
}
