#include <string.h>
#include "operations.h"
#include "helpers.h"

void matrix_add(matrix *a, matrix *b, matrix *out) {
    if (!size_equal(a, b) || !size_equal(a, out)) {
        return;
    }
    unsigned int rows = a->rows, cols = a->cols;
    memcpy(out->data, a->data, sizeof(double) * rows * cols);
    for (int i = 0; i < rows * cols; i++) {
        out->data[i] += b->data[i];
    }
}

void matrix_subtract(matrix *a, matrix *b, matrix *out) {
    if (!size_equal(a, b) || !size_equal(a, out)) {
        return;
    }
    unsigned int rows = a->rows, cols = a->cols;
    memcpy(out->data, a->data, sizeof(double) * rows * cols);
    for (int i = 0; i < rows * cols; i++) {
        out->data[i] -= b->data[i];
    }
}

void matrix_multiply(matrix *a, matrix *b, matrix *out) {
    if (!size_equal(a, b) || !size_equal(a, out)) {
        return;
    }
    unsigned int rows = a->rows, cols = a->cols;
    memcpy(out->data, a->data, sizeof(double) * rows * cols);
    for (int i = 0; i < rows * cols; i++) {
        out->data[i] *= b->data[i];
    }
}

void matrix_transpose(matrix *a, matrix *out) {
    if (!is_square(a) || !size_equal(a, out)) {
        return;
    }
    unsigned int rows = a->rows, cols = a->cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            out->data[i * rows + j] = a->data[j * rows + i];
        }
    }
}
