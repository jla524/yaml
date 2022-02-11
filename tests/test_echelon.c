#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "test_echelon.h"
#include "../src/echelon.h"
#include "../src/init.h"
#include "../src/inner.h"
#include "../src/helpers.h"

void test_find_pivot() {
    assert(find_pivot(NULL, 8) == -1);
    double arr[] = {1, 4, 6, 0, 1, 7, 0, 0, 0};
    matrix *mat = from_array(arr, 3, 3);
    assert(find_pivot(mat, -1) == -1);
    assert(find_pivot(mat, 0) == 0);
    assert(find_pivot(mat, 1) == 1);
    assert(find_pivot(mat, 2) == -1);
    assert(find_pivot(mat, 4) == -1);
    matrix_free(mat);
}

void test_is_row_echelon() {
    assert(!is_row_echelon(NULL));
    assert(!is_row_echelon(ones(2, 2)));
    assert(is_row_echelon(zeros(1, 3)));
    assert(is_row_echelon(identity(5)));
    double arr[] = {0, 1, 2, 3};
    matrix *mat = from_array(arr, 2, 2);
    assert(!is_row_echelon(mat));
    swap_rows(mat, 0, 1);
    assert(is_row_echelon(mat));
    matrix_free(mat);
}

void test_is_reduced_row_echelon() {
    assert(!is_reduced_row_echelon(NULL));
    assert(!is_reduced_row_echelon(ones(3, 1)));
    assert(is_reduced_row_echelon(zeros(2, 2)));
    assert(is_reduced_row_echelon(identity(4)));
    double arr[] = {1, 0, 2, 0, 1, 0};
    matrix *mat = from_array(arr, 2, 3);
    assert(!is_reduced_row_echelon(mat));
    int index = get_index(mat, 0, 2);
    mat->data[index] = 0;
    assert(is_reduced_row_echelon(mat));
    matrix_free(mat);
}

void test_compute_row_echelon();

void test_compute_reduced_row_echelon();

void test_all_echelon() {
    printf("Testing row echelon functions...\t");
    test_find_pivot();
    test_is_row_echelon();
    test_is_reduced_row_echelon();
    printf("Passed\n");
}
