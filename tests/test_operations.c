#include <stdio.h>
#include <assert.h>
#include "../src/init.h"
#include "../src/operations.h"

int main() {
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
    return 0;
}
