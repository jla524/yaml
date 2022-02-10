#include <stdio.h>
#include <assert.h>
#include "../src/init.h"
#include "../src/operations.h"

void test_matrix_add() {
    double array_a[] = {1, 2, 3, 5};
    double array_b[] = {2, 5, 7, 9};
    matrix *mat_a = from_array(array_a, 2, 2);
    matrix *mat_b = from_array(array_b, 2, 2);
    matrix *mat_sum = matrix_new(2, 2);
    matrix_add(mat_a, mat_b, mat_sum);
    for (int i = 0; i < 2 * 2; i++) {
        double expected = array_a[i] + array_b[i];
        assert(mat_sum->data[i] == expected);
    }
    matrix_free(mat_a);
    matrix_free(mat_b);
    matrix_free(mat_sum);
}

void test_matrix_subtract() {
    double array_a[] = {7, 8, 5, -3};
    double array_b[] = {3, 8, 4, 6};
    matrix *mat_a = from_array(array_a, 2, 2);
    matrix *mat_b = from_array(array_b, 2, 2);
    matrix *mat_diff = matrix_new(2, 2);
    matrix_subtract(mat_a, mat_b, mat_diff);
    for (int i = 0; i < 2 * 2; i++) {
        double expected = array_a[i] - array_b[i];
        assert(mat_diff->data[i] == expected);
    }
    matrix_free(mat_a);
    matrix_free(mat_b);
    matrix_free(mat_diff);
}

void test_matrix_multiply() {
    double array_a[] = {2, 5, 3, 4};
    double array_b[] = {4, 7, 1, 5};
    matrix *mat_a = from_array(array_a, 2, 2);
    matrix *mat_b = from_array(array_b, 2, 2);
    matrix *mat_prod = matrix_new(2, 2);
    matrix_multiply(mat_a, mat_b, mat_prod);
    for (int i = 0; i < 2 * 2; i++) {
        double expected = array_a[i] * array_b[i];
        assert(mat_prod->data[i] == expected);
    }
    matrix_free(mat_a);
    matrix_free(mat_b);
    matrix_free(mat_prod);
}

void test_matrix_transpose() {
    double arr[] = {1, 4, 5, 2, 7, 3, 8, -3, 1};
    matrix *source = from_array(arr, 3, 3);
    matrix *transposed = matrix_new(3, 3);
    matrix_transpose(source, transposed);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            double expected = source->data[j * 3 + i];
            double actual = transposed->data[i * 3 + j];
            assert(expected == actual);
        }
    }
    matrix_free(source);
    matrix_free(transposed);
}

void test_matrix_dot() {
    double array_a[] = {1, 4, 2, 2, 3, 2, 3, 4, 2};
    double array_b[] = {7, 2, 2, 2, 7, 2, 1, 6, 6};
    matrix *mat_a = from_array(array_a, 3, 3);
    matrix *mat_b = from_array(array_b, 3, 3);
    matrix *mat_dot = matrix_new(3, 3);
    matrix_dot(mat_a, mat_b, mat_dot);
    double expected[] = {17, 42, 22, 22, 37, 22, 31, 46, 26};
    for (int i = 0; i < 3 * 3; i++) {
        assert(mat_dot->data[i] == expected[i]);
    }
    matrix_free(mat_a);
    matrix_free(mat_b);
    matrix_free(mat_dot);
}

int main() {
    printf("Testing matrix operations...\n");
    test_matrix_add();
    test_matrix_subtract();
    test_matrix_multiply();
    test_matrix_transpose();
    test_matrix_dot();
    printf("Done\n");
    return 0;
}
