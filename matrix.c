#include <stdlib.h>
#include "matrix.h"

matrix *matrix_new(unsigned int rows, unsigned int cols) {
    matrix *mat = malloc(sizeof(*mat));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(sizeof(double) * rows * cols);
    return mat;
}

void matrix_free(matrix *mat) {
    free(mat->data);
    free(mat);
}

bool is_square(matrix *mat) {
    return mat->rows == mat->cols;
}
