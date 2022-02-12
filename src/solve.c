#include <stdlib.h>
#include "solve.h"
#include "init.h"
#include "echelon.h"

matrix *row_reduction(matrix *a, matrix *b) {
    if (a == NULL || b == NULL || b->cols != 1) {
        return NULL;
    }
    matrix *mat = concat_col(a, b);
    compute_reduced_row_echelon(mat);
    return mat;
}
