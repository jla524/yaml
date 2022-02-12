#include <stdio.h>
#include <stdlib.h>
#include "solve.h"
#include "init.h"
#include "echelon.h"
#include "helpers.h"
#include "inner.h"

matrix *row_reduction(matrix *a, matrix *b) {
    if (a == NULL || b == NULL || b->cols != 1) {
        return NULL;
    }
    matrix *mat = concat_col(a, b);
    compute_reduced_row_echelon(mat);
    return mat;
}

double determinant(matrix *mat) {
    if (mat == NULL || !is_square(mat)) {
        return 0;
    }
    if (mat->rows == 2) {
        double a = get_value(mat, 0, 0);
        double b = get_value(mat, 0, 1);
        double c = get_value(mat, 1, 0);
        double d = get_value(mat, 1, 1);
        return a * d - b * c;
    }
    double result = 0;
    for (int i = 0; i < mat->cols; i++) {
        int sign = i % 2 ? -1 : 1;
        double constant = get_value(mat, 0, i);
        matrix *sub_mat = remove_row(remove_col(mat, i), 0);
        result += sign * constant * determinant(sub_mat);
    }
    return result;
}
