#include <stdlib.h>
#include "inner.h"
#include "helpers.h"

double *get_row(matrix *mat, int number) {
    if (mat == NULL || !row_valid(mat, number)) {
        return NULL;
    }
    unsigned int cols = mat->cols;
    double *row = malloc(sizeof(double) * cols);
    for (int i = 0; i < cols; i++) {
        row[i] = mat->data[number * cols + i];
    }
    return row;
}

double *get_column(matrix *mat, int number);
void swap_rows(matrix *mat, int row_a, int row_b);
void subtract_row(matrix *mat, int row_a, int row_b, double factor);
