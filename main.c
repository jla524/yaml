#include <stdio.h>
#include <assert.h>
#include "matrix.h"
#include "init.h"

int main() {
    printf("Testing matrix definition...\n");
    matrix *test_def = matrix_new(2500, 7500);
    assert(!is_square(test_def));
    matrix_free(test_def);

    printf("Testing matrix initialzation...\n");
    matrix *test_init = zeros(1337, 7);
    for (int i = 0; i < 1337 * 7; i++) {
        assert(test_init->data[i] == 0);
    }

    return 0;
}
