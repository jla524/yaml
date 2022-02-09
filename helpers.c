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
            printf("\t%lf ", mat->data[i * mat->rows + j]);
        }
        printf("\n");
    }
}

bool size_equal(matrix *a, matrix *b) {
    if (a == NULL && b == NULL) {
        return true;
    }
    if (a == NULL || b == NULL) {
        return false;
    }
    return a->rows == b->rows && a->cols == b->cols;
}
