#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/init.h"
#include "../src/inner.h"
#include "../src/helpers.h"

void test_get_row() {
    assert(get_row(NULL, 3) == NULL);
    double arr[] = {3, 2, 0, -1, 4, -8};
    matrix *mat = from_array(arr, 3, 2);
    assert(get_row(mat, -1) == NULL);
    assert(get_row(mat, 3) == NULL);
    double *row;
    for (int i = 0; i < 3; i++) {
        row = get_row(mat, i);
        for (int j = 0; j < 2; j++) {
            double expected = arr[i * 2 + j];
            assert(expected == row[j]);
        }
    }
    matrix_free(mat);
    free(row);
}

void test_get_column() {
    assert(get_column(NULL, 5) == NULL);
    double arr[] = {5, 3, 0, 1, 7, 5};
    matrix *mat = from_array(arr, 2, 3);
    assert(get_column(mat, -1) == NULL);
    assert(get_column(mat, 3) == NULL);
    double *column;
    for (int i = 0; i < 3; i++) {
        column = get_column(mat, i);
        for (int j = 0; j < 2; j++) {
            double expected = arr[j * 3 + i];
            assert(expected == column[j]);
        }
    }
    matrix_free(mat);
    free(column);
}

void test_swap_rows() {
    double arr[] = {1, 3, 2, 4};
    matrix *mat = from_array(arr, 2, 2);
    matrix *swapped = copy(mat);
    swap_rows(swapped, 0, 1);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            double expected = get_value(mat, i, j);
            double actual = get_value(swapped, 1 - i, j);
            assert(expected == actual);
        }
    }
    matrix_free(mat);
    matrix_free(swapped);
}

void test_subtract_row() {
    double arr[] = {2, 4, 2, 1, 3, 3};
    matrix *mat = from_array(arr, 2, 3);
    subtract_row(mat, 1, 0, 0.5);
    double expected[] = {2, 4, 2, 0, 1, 2};
    for (int i = 0; i < 2 * 3; i++) {
        assert(mat->data[i] == expected[i]);
    }
    matrix_free(mat);
}

void test_all_inner() {
    printf("Testing inner operations...\t\t");
    test_get_row();
    test_get_column();
    test_swap_rows();
    test_subtract_row();
    printf("Passed\n");
}
