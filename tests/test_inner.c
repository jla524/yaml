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
    unsigned int rows = 3, cols = 2;
    matrix *mat = from_array(arr, rows, cols);
    assert(get_row(mat, -1) == NULL);
    assert(get_row(mat, 3) == NULL);
    double *row_arr[rows];
    for (int i = 0; i < rows; i++) {
        row_arr[i] = get_row(mat, i);
        for (int j = 0; j < cols; j++) {
            double expected = arr[i * cols + j];
            double actual = row_arr[i][j];
            assert(expected == actual);
        }
        free(row_arr[i]);
    }
    matrix_free(mat);
}

void test_get_column() {
    assert(get_column(NULL, 5) == NULL);
    double arr[] = {5, 3, 0, 1, 7, 5};
    unsigned int rows = 2, cols = 3;
    matrix *mat = from_array(arr, rows, cols);
    assert(get_column(mat, -1) == NULL);
    assert(get_column(mat, 3) == NULL);
    double *column_arr[cols];
    for (int i = 0; i < 3; i++) {
        column_arr[i]= get_column(mat, i);
        for (int j = 0; j < 2; j++) {
            double expected = arr[j * cols + i];
            assert(expected == column_arr[i][j]);
        }
        free(column_arr[i]);
    }
    matrix_free(mat);
}

void test_swap_rows() {
    double arr[] = {1, 3, 2, 4};
    unsigned int rows = 2, cols = 2;
    matrix *mat = from_array(arr, rows, cols);
    matrix *swapped = copy(mat);
    swap_rows(swapped, 0, 1);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
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
    unsigned int rows = 2, cols = 3;
    matrix *mat = from_array(arr, 2, 3);
    subtract_row(mat, 1, 0, 0.5);
    double expected[] = {2, 4, 2, 0, 1, 2};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double actual = get_value(mat, i, j);
            assert(expected[i * cols + j] == actual);
        }
    }
    matrix_free(mat);
}

void test_insert_row() {
    double arr_a[] = {1, 2, 5, 6};
    unsigned int rows_a = 2, rows_b = 1, cols = 2;
    matrix *mat_a = from_array(arr_a, rows_a, cols);
    assert(insert_row(mat_a, NULL, 0) == NULL);
    assert(insert_row(mat_a, mat_a, 3) == NULL);
    double arr_b[] = {3, 4};
    matrix *mat_b = from_array(arr_b, rows_b, cols);
    matrix *result = insert_row(mat_a, mat_b, 1);
    assert(result != NULL);
    assert(result->rows == rows_a + rows_b);
    assert(result->cols == cols);
    for (int i = 0; i < result->rows * cols; i++) {
        assert(result->data[i] == i + 1);
    }
    matrix_free(mat_a);
    matrix_free(mat_b);
    matrix_free(result);
}

void test_insert_col() {
    double arr_a[] = {1, 3, 4, 6};
    unsigned int rows = 2, cols_a = 2, cols_b = 1;
    matrix *mat_a = from_array(arr_a, rows, cols_a);
    assert(insert_row(mat_a, NULL, 1) == NULL);
    assert(insert_row(mat_a, mat_a, -1) == NULL);
    double arr_b[] = {2, 5};
    matrix *mat_b = from_array(arr_b, rows, cols_b);
    matrix *result = insert_col(mat_a, mat_b, 1);
    assert(result != NULL);
    assert(result->rows == rows);
    assert(result->cols == cols_a + cols_b);
    for (int i = 0; i < rows * result->cols; i++) {
        assert(result->data[i] == i + 1);
    }
    matrix_free(mat_a);
    matrix_free(mat_b);
    matrix_free(result);
}

void test_remove_row() {
    assert(remove_row(NULL, 1) == NULL);
    double arr[] = {1, 3, 2, 4};
    unsigned int rows = 2, cols = 2;
    matrix *mat = from_array(arr, rows, cols);
    assert(remove_row(mat, 4) == NULL);
    int target_row = 0;
    matrix *new = remove_row(mat, target_row);
    assert(new != NULL);
    assert(new->rows == rows - 1);
    assert(new->cols == cols);
    for (int i = 0; i < new->rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = (i + (i >= target_row)) * cols + j;
            double actual = get_value(new, i, j);
            assert(arr[index] == actual);
        }
    }
    matrix_free(mat);
    matrix_free(new);
}

void test_remove_col() {
    assert(remove_col(NULL, 1) == NULL);
    double arr[] = {6, 1, 1, 4, -2, 5, 2, 8, 7};
    unsigned int rows = 3, cols = 3;
    matrix *mat = from_array(arr, rows, cols);
    assert(remove_col(mat, -2) == NULL);
    int target_col = 1;
    matrix *new = remove_col(mat, target_col);
    assert(new != NULL);
    assert(new->rows == rows);
    assert(new->cols == cols - 1);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < new->cols; j++) {
            int index = i * cols + j + (j >= target_col);
            double actual = get_value(new, i, j);
            assert(arr[index] == actual);
        }
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
