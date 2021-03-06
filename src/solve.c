#include <stdlib.h>
#include "solve.h"
#include "init.h"
#include "echelon.h"
#include "helpers.h"
#include "inner.h"

double determinant(matrix *mat) {
    if (mat == NULL || !is_square(mat)) {
        return 0;
    }
    if (mat->rows == 1) {
        return get_value(mat, 0, 0);
    }
    if (mat->rows == 2) {
        double a = get_value(mat, 0, 0);
        double b = get_value(mat, 0, 1);
        double c = get_value(mat, 1, 0);
        double d = get_value(mat, 1, 1);
        return a * d - b * c;
    }
    double result = 0;
    matrix *partial_mats[mat->cols];
    matrix *sub_mats[mat->cols];
    for (int i = 0; i < mat->cols; i++) {
        int sign = i % 2 ? -1 : 1;
        double constant = get_value(mat, 0, i);
        partial_mats[i] = remove_col(mat, i);
        sub_mats[i] = remove_row(partial_mats[i], 0);
        result += sign * constant * determinant(sub_mats[i]);
        matrix_free(partial_mats[i]);
        matrix_free(sub_mats[i]);
    }
    return result;
}

matrix *inverse(matrix *mat) {
    if (mat == NULL || mat->rows != mat->cols) {
        return NULL;
    }
    matrix *eye = identity(mat->rows);
    matrix *result = concat_col(mat, eye);
    compute_reduced_row_echelon(result);
    matrix_free(eye);
    return result;
}

matrix *row_reduction(matrix *a, matrix *b) {
    if (a == NULL || b == NULL || b->cols != 1) {
        return NULL;
    }
    matrix *mat = concat_col(a, b);
    compute_reduced_row_echelon(mat);
    return mat;
}

int rank(matrix *mat) {
    if (mat == NULL) {
        return 0;
    }
    compute_row_echelon(mat);
    int non_zeros= 0;
    for (int i = 0; i < mat->rows; i++) {
        if (find_row_pivot(mat, i) != -1) {
            non_zeros++;
        }
    }
    return non_zeros;
}
