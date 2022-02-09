#include <stdio.h>
#include <assert.h>
#include "matrix.h"
#include "init.h"
#include "operations.h"

void test_matrix() {
    printf("Testing matrix definition...\n");
    matrix *test_def = matrix_new(25, 75);
    assert(!is_square(test_def));
    matrix_free(test_def);
}

void test_init() {
    printf("Testing matrix initialzation...\n");
    matrix *test_zeros = zeros(13, 37);
    for (int i = 0; i < 13 * 37; i++) {
        assert(test_zeros->data[i] == 0);
    }
    matrix *test_identity = identity(10);
    matrix *test_copy = copy(test_identity);
    for (int i = 0; i < 10; i++) {
        assert(test_identity->data[i * 10 + i] == 1);
        assert(test_copy->data[i * 10 + i] == 1);
    }
    matrix_free(test_zeros);
    matrix_free(test_identity);
    matrix_free(test_copy);
}

void test_operations() {
    printf("Testing matrix operations...\n");
    matrix *test_ones = ones(7, 7);
    matrix *test_identity = identity(7);
    matrix_add(test_ones, test_identity, test_ones);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            double expected = i == j ? 2.0 : 1.0;
            assert(test_ones->data[i * 7 + j] == expected);
        }
    }
    matrix *test_rand = rands(3, 3);
    matrix *test_transpose = matrix_new(3, 3);
    matrix_transpose(test_rand, test_transpose);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            double actual = test_rand->data[i * 3 + j];
            double expected = test_transpose->data[j * 3 + i];
            assert(actual == expected);
        }
    }
    matrix_free(test_ones);
    matrix_free(test_identity);
    matrix_free(test_rand);
    matrix_free(test_transpose);
}

int main() {
    printf("Tests begin\n");
    test_matrix();
    test_init();
    test_operations();
    printf("Done\n");
    return 0;
}
