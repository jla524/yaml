#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "test_solve.h"
#include "../src/solve.h"
#include "../src/init.h"
#include "../src/helpers.h"

void test_row_reduction() {
    assert(row_reduction(NULL, NULL) == NULL);
    double arr_a[] = {1, 3, -2, 3, 5, 6, 2, 4, 3};
    matrix *mat_a = from_array(arr_a, 3, 3);
    assert(row_reduction(mat_a, mat_a) == NULL);
    double arr_b[] = {5, 7, 8};
    matrix *mat_b = from_array(arr_b, 3, 1);
    matrix *final = row_reduction(mat_a, mat_b);
    assert(final != NULL);
    assert(final->rows == 3);
    assert(final->cols == 4);
    double expected[] = {1, 0, 0, -15, 0, 1, 0, 8, 0, 0, 1, 2};
    for (int i = 0; i < 3 * 4; i++) {
        assert(expected[i] == final->data[i]);
    }
    matrix_free(mat_a);
    matrix_free(mat_b);
    matrix_free(final);
}

void test_determinant() {
    assert(determinant(NULL) == 0);
    assert(determinant(zeros(3, 2)) == 0);
    double easy_arr[] = {3, 8, 4, 6};
    matrix *easy_mat = from_array(easy_arr, 2, 2);
    assert(determinant(easy_mat) == -14);
    matrix_free(easy_mat);
    double hard_arr[] = {6, 1, 1, 4, -2, 5, 2, 8, 7};
    matrix *hard_mat = from_array(hard_arr, 3, 3);
    assert(determinant(hard_mat) == -306);
}

void test_all_solve() {
    printf("Testing equation solvers...\t\t");
    test_row_reduction();
    test_determinant();
    printf("Passed\n");
}
