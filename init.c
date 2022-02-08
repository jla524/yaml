#include <stdlib.h>
#include <time.h>
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
            mat->data[i * mat->rows + j] = (double) rand();
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
        mat->data[i * mat->rows + i] = 1;
    }
    return mat;
}

matrix *from_file(char *path);
