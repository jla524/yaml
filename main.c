#include <stdio.h>
#include <assert.h>
#include "matrix.h"
#include "init.h"

void test_matrix() {
    printf("Testing matrix definition...\n");
    matrix *test_def = matrix_new(25, 75);
    assert(!is_square(test_def));
    matrix_free(test_def);
}

void test_init() {
    printf("Testing matrix initialzation...\n");
    matrix *test_zero = zeros(13, 37);
    for (int i = 0; i < 13 * 37; i++) {
        assert(test_zero->data[i] == 0);
    }
    matrix *test_identity = identity(10);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int expected = i == j ? 1 : 0;
            assert(test_identity->data[i * 10 + j] == expected);
        }
    }
    matrix_free(test_zero);
    matrix_free(test_identity);
}

int main() {
    test_matrix();
    test_init();
    printf("Done\n");
    return 0;
}
