#include <stdio.h>
#include <assert.h>
#include "matrix.h"

int main() {
    printf("Testing matrix definitions...\n");
    matrix *test_matrix = matrix_new(2500, 7500);
    assert(!is_square(test_matrix));
    matrix_free(test_matrix);
    return 0;
}
