#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "../src/helpers.h"
#include "../src/matrix.h"

void test_size_equal() {
    assert(!size_equal(NULL, NULL));
    matrix *mat_a = matrix_new(2, 8);
    matrix *mat_b = matrix_new(3, 5);
    matrix *mat_c = matrix_new(2, 8);
    assert(!size_equal(mat_a, mat_b));
    assert(!size_equal(mat_b, mat_c));
    assert(size_equal(mat_a, mat_c));
    matrix_free(mat_a);
    matrix_free(mat_b);
    matrix_free(mat_c);
}

void test_row_valid() {
    assert(!row_valid(NULL, 5));
    matrix *mat = matrix_new(7, 2);
    assert(!row_valid(mat, -2));
    assert(!row_valid(mat, 9));
    assert(row_valid(mat, 0));
    assert(row_valid(mat, 5));
    assert(row_valid(mat, 7));
    matrix_free(mat);
}

void test_all_helpers() {
    printf("Testing helper functions...\t\t");
    test_size_equal();
    //test_row_valid();
    printf("Passed\n");
}
