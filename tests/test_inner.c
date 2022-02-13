#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "test_inner.h"
#include "../src/init.h"
#include "../src/inner.h"
#include "../src/helpers.h"

void test_get_row() {
    assert(get_row(NULL, 3) == NULL);
    double arr[] = {3, 2, 0, -1, 4, -8};
    matrix *mat = from_array(arr, 3, 2);
    assert(get_row(mat, -1) == NULL);
    assert(get_row(mat, 3) == NULL);
    double *rows[3];
    for (int i = 0; i < 3; i++) {
        rows[i] = get_row(mat, i);
        for (int j = 0; j < 2; j++) {
            double expected = arr[i * 2 + j];
            assert(expected == rows[i][j]);
        }
        free(rows[i]);
    }
    matrix_free(mat);
}

void test_get_column() {
    assert(get_column(NULL, 5) == NULL);
    double arr[] = {5, 3, 0, 1, 7, 5};
    matrix *mat = from_array(arr, 2, 3);
    assert(get_column(mat, -1) == NULL);
    assert(get_column(mat, 3) == NULL);
    double *columns[3];
    for (int i = 0; i < 3; i++) {
        columns[i]= get_column(mat, i);
        for (int j = 0; j < 2; j++) {
            double expected = arr[j * 3 + i];
            assert(expected == columns[i][j]);
        }
        free(columns[i]);
    }
    matrix_free(mat);
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

void test_insert_row() {
    double arr_a[] = {1, 2, 5, 6};
    matrix *mat_a = from_array(arr_a, 2, 2);
    assert(insert_row(mat_a, NULL, 0) == NULL);
    assert(insert_row(mat_a, mat_a, 3) == NULL);
    double arr_b[] = {3, 4};
    matrix *mat_b = from_array(arr_b, 1, 2);
    matrix *result = insert_row(mat_a, mat_b, 1);
    assert(result != NULL);
    assert(result->rows == 3);
    assert(result->cols == 2);
    for (int i = 0; i < 3 * 2; i++) {
        assert(result->data[i] == i + 1);
    }
    matrix_free(mat_a);
    matrix_free(mat_b);
    matrix_free(result);
}

void test_insert_col() {
    double arr_a[] = {1, 3, 4, 6};
    matrix *mat_a = from_array(arr_a, 2, 2);
    assert(insert_row(mat_a, NULL, 1) == NULL);
    assert(insert_row(mat_a, mat_a, -1) == NULL);
    double arr_b[] = {2, 5};
    matrix *mat_b = from_array(arr_b, 2, 1);
    matrix *result = insert_col(mat_a, mat_b, 1);
    assert(result != NULL);
    assert(result->rows == 2);
    assert(result->cols == 3);
    for (int i = 0; i < 2 * 3; i++) {
        assert(result->data[i] == i + 1);
    }
    matrix_free(mat_a);
    matrix_free(mat_b);
    matrix_free(result);
}

void test_remove_row() {
    assert(remove_row(NULL, 1) == NULL);
    double arr[] = {1, 3, 2, 4};
    matrix *mat = from_array(arr, 2, 2);
    assert(remove_row(mat, 4) == NULL);
    matrix *new = remove_row(mat, 0);
    assert(new != NULL);
    assert(new->rows = 1);
    assert(new->cols = 2);
    for (int i = 0; i < 2; i++) {
        assert(new->data[i] == arr[i + 2]);
    }
    matrix_free(mat);
    matrix_free(new);
}

void test_remove_col() {
    assert(remove_col(NULL, 1) == NULL);
    double arr[] = {6, 1, 1, 4, -2, 5, 2, 8, 7};
    matrix *mat = from_array(arr, 3, 3);
    assert(remove_col(mat, -2) == NULL);
    matrix *new = remove_col(mat, 1);
    assert(new != NULL);
    assert(new->rows = 2);
    assert(new->cols = 1);
    for (int i = 0; i < 2; i++) {
        int index = i / 2 * 2 + (i % 2) * 2;
        assert(new->data[i] == arr[index]);
    }
    matrix_free(mat);
    matrix_free(new);
}

void test_all_inner() {
    printf("Testing inner operations...\t\t");
    test_get_row();
    test_get_column();
    test_swap_rows();
    test_subtract_row();
    test_insert_row();
    test_insert_col();
    test_remove_row();
    test_remove_col();
    printf("Passed\n");
}
