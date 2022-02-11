#include <stdio.h>
#include <assert.h>
#include "test_matrix.h"
#include "../src/matrix.h"

void test_matrix_new() {
    matrix *invalid = matrix_new(0, 3);
    assert(invalid == NULL);
    matrix *valid= matrix_new(1, 3);
    assert(valid != NULL);
    assert(valid->rows == 1);
    assert(valid->cols == 3);
    assert(valid->data != NULL);
    matrix_free(valid);
}

void test_is_square() {
    matrix *test_square = matrix_new(5, 5);
    matrix *test_non_square = matrix_new(7, 2);
    assert(is_square(test_square));
    assert(!is_square(test_non_square));
    matrix_free(test_square);
    matrix_free(test_non_square);
}

void test_all_matrix() {
    printf("Testing matrix definitions...\t\t");
    test_matrix_new();
    test_is_square();
    printf("Passed\n");
}
