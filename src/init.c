#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "init.h"
#include "helpers.h"

matrix *fill(matrix *mat, double val) {
    if (mat == NULL) {
        return NULL;
    }
    for (int i = 0; i < mat->rows * mat->cols; i++) {
        mat->data[i] = val;
    }
    return mat;
}

matrix *zeros(unsigned int rows, unsigned int cols) {
    if (rows == 0 || cols == 0) {
        return NULL;
    }
    matrix *mat = matrix_new(rows, cols);
    return fill(mat, 0);
}

matrix *ones(unsigned int rows, unsigned int cols) { 
    if (rows == 0 || cols == 0) {
        return NULL;
    }
    matrix *mat = matrix_new(rows, cols);
    return fill(mat, 1);
}

matrix *rands(unsigned int rows, unsigned int cols) {
    if (rows == 0 || cols == 0) {
        return NULL;
    }
    srand(time(NULL));
    matrix *mat = matrix_new(rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        mat->data[i] = (double) rand();
    }
    return mat;
}

matrix *identity(unsigned int n) {
    if (n == 0) {
        return NULL;
    }
    matrix *mat = zeros(n, n);
    for (int i = 0; i < n; i++) {
        int index = get_index(mat, i, i);
        mat->data[index] = 1;
    }
    return mat;
}

matrix *copy(matrix *source) {
    if (source == NULL) {
        return NULL;
    }
    unsigned int rows = source->rows, cols = source->cols;
    matrix *mat = matrix_new(rows, cols);
    memcpy(mat->data, source->data, sizeof(double) * rows * cols);
    return mat;
}

matrix *concat_row(matrix *a, matrix *b) {
    if (a == NULL || b == NULL || a->rows != b->rows) {
        return NULL;
    }
    unsigned int rows = a->rows, cols_a = a->cols, cols_b = b->cols;
    matrix *mat = matrix_new(rows, cols_a + cols_b);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols_a; j++) {
            int index = get_index(mat, i, j);
            mat->data[index] = get_value(a, i, j);
        }
        for (int j = 0; j < cols_b; j++) {
            int index = get_index(mat, i, cols_a + j);
            mat->data[index] = get_value(b, i, j);
        }
    }
    return mat;
}

matrix *concat_col(matrix *a, matrix *b) {
    if (a == NULL || b == NULL || a->cols != b->cols) {
        return NULL;
    }
    unsigned int rows_a = a->rows, rows_b = b->rows, cols = a->cols;
    matrix *mat = matrix_new(rows_a + rows_b, cols);
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols; j++) {
            int index = get_index(mat, i, j);
            mat->data[index] = get_value(a, i, j);
        }
    }
    for (int i = 0; i < rows_b; i++) {
        for (int j = 0; j < cols; j++) {
            int index = get_index(mat, rows_a + i, j);
            mat->data[index] = get_value(b, i, j);
        }
    }
    return mat;
}

matrix *from_array(double data[], unsigned int rows, unsigned int cols) {
    if (data == NULL || rows == 0 || cols == 0) {
        return NULL;
    }
    matrix *mat = matrix_new(rows, cols);
    memcpy(mat->data, data, sizeof(double) * rows * cols);
    return mat;
}

matrix *from_file(char *path) {
    if (path == NULL) {
        return NULL;
    }
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        return NULL;
    }
    unsigned int rows = 0, cols = 0;
    fscanf(fp, "%d", &rows);
    fscanf(fp, "%d", &cols);
    matrix *mat = matrix_new(rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        fscanf(fp, "%lf ", &mat->data[i]);
    }
    fclose(fp);
    return mat;
}
