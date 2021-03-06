#include <stdio.h>
#include <assert.h>
#include "test_helpers.h"
#include "../src/helpers.h"
#include "../src/init.h"
#include "../src/matrix.h"

void test_size_equal() {
    assert(!size_equal(NULL, NULL));
    matrix *mat_a = matrix_new(2, 8);
    matrix *mat_b = matrix_new(3, 5);
    matrix *mat_c = matrix_new(2, 8);
    assert(!size_equal(mat_a, mat_b));
    assert(!size_equal(mat_b, mat_c));
    assert(size_equal(mat_a, mat_c));
    matrix_free(mat_a);
    matrix_free(mat_b);
    matrix_free(mat_c);
}

void test_row_valid() {
    assert(!row_valid(NULL, 5));
    matrix *mat = matrix_new(7, 2);
    assert(!row_valid(mat, -2));
    assert(!row_valid(mat, 7));
    assert(!row_valid(mat, 9));
    assert(row_valid(mat, 0));
    assert(row_valid(mat, 5));
    assert(row_valid(mat, 6));
    matrix_free(mat);
}

void test_col_valid() {
    assert(!row_valid(NULL, 2));
    matrix *mat = matrix_new(1, 9);
    assert(!col_valid(mat, -1));
    assert(!col_valid(mat, 9));
    assert(col_valid(mat, 7));
    matrix_free(mat);
}

void test_get_index() {
    double arr[] = {0.3, 0.5, 0.0, 0.1, 0.8, 0.1};
    unsigned int rows = 2, cols = 3;
    matrix *mat = from_array(arr, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double expected = arr[i * cols + j];
            double actual = get_value(mat, i, j);
            assert(expected == actual);
        }
    }
    matrix_free(mat);
}

void test_get_value() {
    double arr[] = {0.5, 2.4, 1.3, 0.1, 1.5, 2.7};
    unsigned int rows = 3, cols = 2;
    matrix *mat = from_array(arr, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double expected = arr[i * cols + j];
            double actual = get_value(mat, i, j);
            assert(expected == actual);
        }
    }
    matrix_free(mat);
}

void test_all_helpers() {
    printf("Testing helper functions...\t\t");
    test_size_equal();
    test_row_valid();
    test_col_valid();
    test_get_index();
    test_get_value();
    printf("Passed\n");
}
