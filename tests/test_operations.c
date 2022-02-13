#include <stdio.h>
#include <assert.h>
#include "test_operations.h"
#include "../src/init.h"
#include "../src/operations.h"
#include "../src/helpers.h"

void test_matrix_add() {
    double array_a[] = {1, 2, 3, 5};
    double array_b[] = {2, 5, 7, 9};
    unsigned int rows = 2, cols = 2;
    matrix *mat_a = from_array(array_a, rows, cols);
    matrix *mat_b = from_array(array_b, rows, cols);
    matrix *mat_sum = matrix_new(rows, cols);
    matrix_add(mat_a, mat_b, mat_sum);
    for (int i = 0; i < rows * cols; i++) {
        double expected = array_a[i] + array_b[i];
        assert(expected == mat_sum->data[i]);
    }
    matrix_free(mat_a);
    matrix_free(mat_b);
    matrix_free(mat_sum);
}

void test_matrix_subtract() {
    double array_a[] = {7, 8, 5, -3};
    double array_b[] = {3, 8, 4, 6};
    unsigned int rows = 2, cols = 2;
    matrix *mat_a = from_array(array_a, rows, cols);
    matrix *mat_b = from_array(array_b, rows, cols);
    matrix *mat_diff = matrix_new(rows, cols);
    matrix_subtract(mat_a, mat_b, mat_diff);
    for (int i = 0; i < rows * cols; i++) {
        double expected = array_a[i] - array_b[i];
        assert(expected == mat_diff->data[i]);
    }
    matrix_free(mat_a);
    matrix_free(mat_b);
    matrix_free(mat_diff);
}

void test_matrix_multiply() {
    double array_a[] = {2, 5, 3, 4};
    double array_b[] = {4, 7, 1, 5};
    unsigned int rows = 2, cols = 2;
    matrix *mat_a = from_array(array_a, rows, cols);
    matrix *mat_b = from_array(array_b, rows, cols);
    matrix *mat_prod = matrix_new(rows, cols);
    matrix_multiply(mat_a, mat_b, mat_prod);
    for (int i = 0; i < rows * cols; i++) {
        double expected = array_a[i] * array_b[i];
        assert(expected == mat_prod->data[i]);
    }
    matrix_free(mat_a);
    matrix_free(mat_b);
    matrix_free(mat_prod);
}

void test_matrix_transpose() {
    double arr[] = {1, 4, 5, 2, 7, 3, 8, -3, 1};
    unsigned int rows = 3, cols = 3;
    matrix *source = from_array(arr, rows, cols);
    matrix *transposed = matrix_new(rows, cols);
    matrix_transpose(source, transposed);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double expected = get_value(source, j, i);
            double actual = get_value(transposed, i, j);
            assert(expected == actual);
        }
    }
    matrix_free(source);
    matrix_free(transposed);
}

void test_matrix_dot() {
    double array_a[] = {1, 4, 2, 2, 3, 2, 3, 4, 2};
    double array_b[] = {7, 2, 2, 2, 7, 2, 1, 6, 6};
    unsigned int rows = 3, cols = 3;
    matrix *mat_a = from_array(array_a, rows, cols);
    matrix *mat_b = from_array(array_b, rows, cols);
    matrix *mat_dot = matrix_new(rows, cols);
    matrix_dot(mat_a, mat_b, mat_dot);
    double expected[] = {17, 42, 22, 22, 37, 22, 31, 46, 26};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = i * cols + j;
            double actual = get_value(mat_dot, i, j);
            assert(expected[index] == actual);
        }
    }
    matrix_free(mat_a);
    matrix_free(mat_b);
    matrix_free(mat_dot);
}

void test_all_operations() {
    printf("Testing matrix operations...\t\t");
    test_matrix_add();
    test_matrix_subtract();
    test_matrix_multiply();
    test_matrix_transpose();
    test_matrix_dot();
    printf("Passed\n");
}
