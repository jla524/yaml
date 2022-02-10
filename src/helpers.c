#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

inline void print_matrix(matrix *mat) {
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

inline bool size_equal(matrix *a, matrix *b) {
    if (a == NULL || b == NULL) {
        return false;
    }
    bool rows_equal = a->rows == b->rows;
    bool cols_equal = a->cols == b->cols;
    return rows_equal && cols_equal;
}
