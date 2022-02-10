#include <assert.h>
#include <stdbool.h>
#include "../src/helpers.c"
#include "../src/matrix.h"

void test_size_equal() {
    bool invalid = size_equal(NULL, NULL);
    assert(invalid == false);
    matrix *mat_a = matrix_new(2, 8);
    matrix *mat_b = matrix_new(3, 5);
    matrix *mat_c = matrix_new(2, 8);
    assert(!size_equal(mat_a, mat_b));
    assert(!size_equal(mat_b, mat_c));
    assert(size_equal(mat_a, mat_c));
}

void test_all_helpers() {
    printf("Testing helper functions...\t\t");
    test_size_equal();
    printf("Passed\n");
}
