#include <stdio.h>
#include <assert.h>
#include "../src/init.h"

void test_fill() {
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
    for (int i = 0; i < 8 * 5; i++) {
        assert(one->data[i] == 1);
    }
    matrix_free(one);
}

void test_rands() {
    matrix *invalid = rands(0, 0);
    assert(invalid == NULL);
    matrix *mat = rands(2, 3);
    assert(mat != NULL);
    assert(mat->rows == 2);
    assert(mat->cols == 3);
    assert(mat->data != NULL);
    matrix_free(mat);
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

int main() {
    printf("Testing matrix initialzation...\n");
    test_fill();
    test_zeros();
    test_ones();
    test_identity();
    // TODO: test copy and from_file
    printf("Done\n");
    return 0;
}
