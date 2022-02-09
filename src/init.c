#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "init.h"

matrix *fill(matrix *mat, double val) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            mat->data[i * mat->rows + j] = val;
        }
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
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat->data[i * rows + j] = (double) rand();
        }
    }
    return mat;
}

matrix *identity(unsigned int n) {
    if (n == 0) {
        return NULL;
    }
    matrix *mat = zeros(n, n);
    for (int i = 0; i < n; i++) {
        mat->data[i * n + i] = 1;
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

matrix *from_file(char *path) {
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        return NULL;
    }
    unsigned int rows = 0, cols = 0;
    fscanf(fp, "%d", &rows);
    fscanf(fp, "%d", &cols);
    matrix *mat = matrix_new(rows, cols);
    for (int i = 0; i < rows * cols; i++) {
        fscanf(fp, "%lf\t", &mat->data[i]);
    }
    fclose(fp);
    return mat;
}
