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
        row[i] = get_value(mat, number, i);
    }
    return row;
}

double *get_column(matrix *mat, int number) {
    if (mat == NULL || !col_valid(mat, number)) {
        return NULL;
    }
    unsigned int rows = mat->rows;
    double *column = malloc(sizeof(double) * rows);
    for (int i = 0; i < rows; i++) {
        column[i] = get_value(mat, i, number);
    }
    return column;
}
void swap_rows(matrix *mat, int row_a, int row_b) {
    if (mat == NULL || !row_valid(mat, row_a) || !row_valid(mat, row_b)) {
        return;
    }
    unsigned int cols = mat->cols;
    for (int i = 0; i < cols; i++) {
       double temp = get_value(mat, row_a, i);
       unsigned int index_a = get_index(mat, row_a, i);
       unsigned int index_b = get_index(mat, row_b, i);
       mat->data[index_a] = get_value(mat, row_b, i);
       mat->data[index_b] = temp;
    }
}

void subtract_row(matrix *mat, int row_a, int row_b, double factor) {
    if (mat == NULL || !row_valid(mat, row_a)
        || !row_valid(mat, row_b) || factor == 0)  {
        return;
    }
    unsigned int cols = mat->cols;
    for (int i = 0; i < cols; i++) {
        unsigned int index = get_index(mat, row_a, i);
        double value = get_value(mat, row_b, i);
        mat->data[index] -= value * factor;
    }
}
