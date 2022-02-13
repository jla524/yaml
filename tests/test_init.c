#include <stdio.h>
#include <assert.h>
#include "../src/init.h"
#include "../src/helpers.h"

void test_fill() {
    assert(fill(NULL, 5) == NULL);
    unsigned int rows = 9, cols = 3;
    matrix *mat = matrix_new(rows, cols);
    assert(mat != NULL);
    fill(mat, 9.45);
    assert(mat->rows == rows);
    assert(mat->cols == cols);
    for (int i = 0; i < rows * cols; i++) {
        assert(mat->data[i] == 9.45);
    }
    matrix_free(mat);
}

void test_zeros() {
    assert(zeros(0, 5) == NULL);
    unsigned int rows = 3, cols = 7;
    matrix *zero = zeros(rows, cols);
    assert(zero != NULL);
    assert(zero->rows == rows);
    assert(zero->cols == cols);
    for (int i = 0; i < rows * cols; i++) {
        assert(zero->data[i] == 0);
    }
    matrix_free(zero);
}

void test_ones() {
    assert(ones(27, 0) == NULL);
    unsigned int rows = 8, cols = 5;
    matrix *one = ones(rows, cols);
    assert(one != NULL);
    assert(one->rows == rows);
    assert(one->cols == cols);
    for (int i = 0; i < rows * cols; i++) {
        assert(one->data[i] == 1);
    }
    matrix_free(one);
}

void test_rands() {
    assert(rands(0, 0) == NULL);
    unsigned int rows = 2, cols = 3;
    matrix *rand = rands(rows, cols);
    assert(rand != NULL);
    assert(rand->rows == rows);
    assert(rand->cols == cols);
    matrix_free(rand);
}

void test_identity() {
    assert(identity(0) == NULL);
    unsigned int n = 3;
    matrix *eye = identity(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double expected = i == j ? 1.0 : 0.0;
            int index = get_index(eye, i, j);
            assert(eye->data[index] == expected);
        }
    }
    matrix_free(eye);
}

void test_copy() {
    assert(copy(NULL) == NULL);
    unsigned int rows = 3, cols = 7;
    matrix *rand = rands(rows, cols);
    matrix *clone = copy(rand);
    assert(clone != NULL);
    assert(clone->rows == rows);
    assert(clone->cols == cols);
    for (int i = 0; i < rows * cols; i++) {
        assert(clone->data[i] == rand->data[i]);
    }
    matrix_free(rand);
    matrix_free(clone);
}

void test_concat_row() {
    double arr_a[] = {1, 2, 3, 4};
    unsigned int rows = 2, cols_a = 2, cols_b = 2;
    matrix *mat_a = from_array(arr_a, rows, cols_a);
    assert(concat_row(NULL, mat_a) == NULL);
    double arr_b[] = {5, 6, 7, 8};
    matrix *mat_b = from_array(arr_b, rows, cols_b);
    matrix *cat = concat_row(mat_a, mat_b);
    assert(cat != NULL);
    assert(cat->rows = rows);
    assert(cat->cols = cols_a + cols_b);
    for (int i = 0; i < rows * cat->cols; i++) {
        assert(cat->data[i] == i + 1);
    }
    matrix_free(mat_a);
    matrix_free(mat_b);
    matrix_free(cat);
}

void test_concat_col() {
    double arr_a[] = {1, 2, 5, 6};
    unsigned int rows_a = 2, rows_b = 2, cols = 2;
    matrix *mat_a = from_array(arr_a, rows_a, cols);
    assert(concat_col(mat_a, NULL) == NULL);
    double arr_b[] = {3, 4, 7, 8};
    matrix *mat_b = from_array(arr_b, rows_b, cols);
    matrix *cat = concat_col(mat_a, mat_b);
    assert(cat != NULL);
    assert(cat->rows = rows_a + rows_b);
    assert(cat->cols = cols);
    for (int i = 0; i < cat->rows * cols; i++) {
        assert(cat->data[i] == i + 1);
    }
    matrix_free(mat_a);
    matrix_free(mat_b);
    matrix_free(cat);
}

void test_from_array() {
    assert(from_array(NULL, 0, 0) == NULL);
    double expected[] = {7.1, 4.0, 9.4, 1.1, 0.8, 3.0};
    unsigned int rows = 3, cols = 2;
    matrix *mat = from_array(expected, rows, cols);
    assert(mat != NULL);
    assert(mat->rows == rows);
    assert(mat->cols == cols);
    for (int i = 0; i < rows * cols; i++) {
        assert(expected[i] == mat->data[i]);
    }
    matrix_free(mat);
}

void test_from_file() {
    assert(from_file(NULL) == NULL);
    assert(from_file("file_that_does_not_exist.txt") == NULL);
    unsigned int rows = 3, cols = 2;
    matrix *mat = from_file("tests/example_matrix.txt");
    assert(mat != NULL);
    assert(mat->rows == rows);
    assert(mat->cols == cols);
    double expected[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6};
    for (int i = 0; i < rows * cols; i++) {
        assert(expected[i] == mat->data[i]);
    }
    matrix_free(mat);
}

void test_all_init() {
    printf("Testing matrix initialzation...\t\t");
    test_fill();
    test_zeros();
    test_ones();
    test_identity();
    test_concat_row();
    test_concat_col();
    test_from_array();
    test_from_file();
    printf("Passed\n");
}
