#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/init.h"
#include "../src/inner.h"

void test_get_row() {
    assert(get_row(NULL, 3) == NULL);
    double arr[] = {3, 2, 0, -1, 4, -8};
    matrix *mat = from_array(arr, 3, 2);
    assert(get_row(mat, -1) == NULL);
    assert(get_row(mat, 3) == NULL);
    double *row;
    for (int i = 0; i < 3; i++) {
        row = get_row(mat, i);
        for (int j = 0; j < 2; j++) {
            double expected = arr[i * 2 + j];
            assert(expected == row[j]);
        }
    }
    matrix_free(mat);
    free(row);
}

void test_get_column();
void test_swap_rows();
void test_subtract_row();

void test_all_inner() {
    printf("Testing inner operations...\t\t");
    test_get_row();
    printf("Passed\n");
}
