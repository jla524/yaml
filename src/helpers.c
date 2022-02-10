#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

void print_matrix(matrix *mat) {
    if (mat == NULL) {
        return;
    }
    printf("Printing matrix...\n");
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("\t%lf", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

bool size_equal(matrix *a, matrix *b) {
    if (a == NULL || b == NULL) {
        return false;
    }
    bool rows_equal = a->rows == b->rows;
    bool cols_equal = a->cols == b->cols;
    return rows_equal && cols_equal;
}

bool row_valid(matrix *mat, int row) {
    if (mat == NULL) {
        return false;
    }
    bool positive = row >= 0;
    bool in_bound = row < mat->rows;
    return positive && in_bound;
}
