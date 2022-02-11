#include <stdlib.h>
#include <assert.h>
#include "test_echelon.h"
#include "../src/echelon.h"
#include "../src/init.h"

void test_find_pivot() {
    assert(find_pivot(NULL, 8) == -1);
    double arr[] = {1, 4, 6, 0, 1, 7};
    matrix *mat = from_array(arr, 2, 3);
    assert(find_pivot(mat, 4) == -1);
}

void test_is_row_echelon();
void test_is_reduced_row_chelon();
void test_compute_row_echelon();
void test_compute_reduced_row_echelon();
