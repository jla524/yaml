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

void multiply_row(matrix *mat, int row, double factor) {
    if (mat == NULL || !row_valid(mat, row) || factor == 0) {
        return;
    }
    for (int i = 0; i < mat->cols; i++) {
        unsigned int index = get_index(mat, row, i);
        mat->data[index] *= factor;
    }
}

void subtract_row(matrix *mat, int row_a, int row_b, double factor) {
    if (mat == NULL || !row_valid(mat, row_a)
        || !row_valid(mat, row_b) || factor == 0)  {
        return;
    }
    for (int i = 0; i < mat->cols; i++) {
        unsigned int index = get_index(mat, row_a, i);
        double value = get_value(mat, row_b, i);
        mat->data[index] -= value * factor;
    }
}

matrix *remove_row(matrix *mat, int number) {
    if (mat == NULL || !row_valid(mat, number) || mat->rows <= 1) {
        return NULL;
    }
    unsigned int rows = mat->rows, cols = mat->cols;
    matrix *new = matrix_new(rows - 1, cols);
    for (int i = 0; i < rows; i++) {
        if (i != number) {
            for (int j = 0; j < cols; j++) {
                double value = get_value(mat, i, j);
                int index = get_index(new, i - number > i, j);
                new->data[index] = value;
            }
        }
    }
    return new;
}

matrix *remove_col(matrix *mat, int number) {
    if (mat == NULL || !col_valid(mat, number) || mat->cols <= 1) {
        return NULL;
    }
    unsigned int rows = mat->rows, cols = mat->cols;
    matrix *new = matrix_new(rows, cols - 1);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j != number) {
                double value = get_value(mat, i, j);
                int index = get_index(new, i, j - number > i);
                new->data[index] = value;
            }
        }
    }
    return new;
}
