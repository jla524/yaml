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
            printf("\t%lf", get_value(mat, i, j));
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

bool col_valid(matrix *mat, int col) {
    if (mat == NULL) {
        return false;
    }
    bool positive = col >= 0;
    bool in_bound = col < mat->cols;
    return positive && in_bound;
}

unsigned int get_index(matrix *mat, int row, int col) {
    if (mat == NULL || !row_valid(mat, row) || !col_valid(mat, col)) {
        return -1;
    }
    int index = row * mat->cols + col;
    return index;
}

double get_value(matrix *mat, int row, int col) {
    unsigned int index = get_index(mat, row, col);
    if (index == -1) {
        return 0;
    }
    double value = mat->data[index];
    return value;
}
