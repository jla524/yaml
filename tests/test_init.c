#include <stdio.h>
#include <assert.h>
#include "../src/init.h"

void test_fill() {
    matrix *invalid = fill(NULL, 5);
    assert(invalid == NULL);
    matrix *mat = matrix_new(9, 3);
    assert(mat != NULL);
    fill(mat, 9.45);
    assert(mat->rows == 9);
    assert(mat->cols == 3);
    for (int i = 0; i < 9 * 3; i++) {
        assert(mat->data[i] == 9.45);
    }
    matrix_free(mat);
}

void test_zeros() {
    matrix *invalid = zeros(0, 5);
    assert(invalid == NULL);
    matrix *zero = zeros(13, 37);
    assert(zero != NULL);
    assert(zero->rows == 13);
    assert(zero->cols == 37);
    for (int i = 0; i < 13 * 37; i++) {
        assert(zero->data[i] == 0);
    }
    matrix_free(zero);
}

void test_ones() {
    matrix *invalid = ones(27, 0);
    assert(invalid == NULL);
    matrix *one = ones(8, 5);
    assert(one != NULL);
    assert(one->rows == 8);
    assert(one->cols == 5);
    for (int i = 0; i < 8 * 5; i++) { assert(one->data[i] == 1);
    }
    matrix_free(one);
}

void test_rands() {
    matrix *invalid = rands(0, 0);
    assert(invalid == NULL);
    matrix *rand = rands(2, 3);
    assert(rand != NULL);
    assert(rand->rows == 2);
    assert(rand->cols == 3);
    matrix_free(rand);
}

void test_copy() {
    matrix *invalid = copy(NULL);
    assert(invalid == NULL);
    matrix *rand = rands(3, 7);
    matrix *clone = copy(rand);
    assert(clone != NULL);
    assert(clone->rows == 3);
    assert(clone->cols == 7);
    for (int i = 0; i < 3 * 7; i++) {
        assert(clone->data[i] == rand->data[i]);
    }
    matrix_free(rand);
    matrix_free(clone);
}

void test_identity() {
    matrix *invalid = identity(0);
    assert(invalid == NULL);
    matrix *eye = identity(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            double expected = i == j ? 1.0 : 0.0;
            assert(eye->data[i * 3 + j] == expected);
        }
    }
    matrix_free(eye);
}

void test_from_array() {
    matrix *invalid = from_array(NULL, 0, 0);
    assert(invalid == NULL);
    double expected[] = {7.1, 4.0, 9.4, 1.1, 0.8, 3.0};
    matrix *mat = from_array(expected, 3, 2);
    assert(mat != NULL);
    assert(mat->rows == 3);
    assert(mat->cols == 2);
    for (int i = 0; i < 3 * 2; i++) {
        assert(expected[i] == mat->data[i]);
    }
}

void test_from_file() {
    matrix *invalid = from_file(NULL);
    assert(invalid == NULL);
    matrix *not_exist = from_file("file_that_does_not_exist.txt");
    assert(not_exist == NULL);
    matrix *mat = from_file("example_matrix.txt");
    assert(mat != NULL);
    assert(mat->rows == 3);
    assert(mat->cols == 2);
    for (int i = 0; i < 3 * 2; i++) {
        double expected = 0.1 * i;
        assert(mat->data[i] == expected);
    }
}

void test_all_init() {
    printf("Testing matrix initialzation...\t");
    test_fill();
    test_zeros();
    test_ones();
    test_identity();
    printf("Passed\n");
}
