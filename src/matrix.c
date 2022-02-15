#include <stdlib.h>
#include "matrix.h"

matrix *matrix_new(unsigned int rows, unsigned int cols) {
    if (rows == 0 || cols == 0) {
        return NULL;
    }
    matrix *mat = malloc(sizeof *mat);
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(sizeof(double) * rows * cols);
    return mat;
}

void matrix_free(matrix *mat) {
    if (mat == NULL) {
        return;
    }
    free(mat->data);
    free(mat);
}

bool is_square(matrix *mat) {
    if (mat == NULL) {
        return false;
    }
    return mat->rows == mat->cols;
}
