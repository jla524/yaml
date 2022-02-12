#include <stdlib.h>
#include "echelon.h"
#include "helpers.h"
#include "inner.h"

int find_row_pivot(matrix *mat, int row) {
    if (mat == NULL || !row_valid(mat, row)) {
        return -1;
    }
    int i = 0;
    while (i < mat->cols && get_value(mat, row, i) == 0) {
        i++;
    }
    return col_valid(mat, i) ? i : -1;
}

int find_col_pivot(matrix *mat, int col, int start) {
    if (mat == NULL || !col_valid(mat, col) || !col_valid(mat, start)) {
        return -1;
    }
    int i = start;
    while (i < mat->rows && get_value(mat, i, col) == 0) {
        i++;
    }
    return row_valid(mat, i) ? i : -1;
}

bool is_row_echelon(matrix *mat) {
    if (mat == NULL) {
        return false;
    }
    // Entries below main diagonal are 0
    unsigned int rows = mat->rows;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            if (get_value(mat, i, j) != 0) {
                return false;
            }
        }
    }
    // The pivot of a non-zero row is strictly to the right of the leading
    // coefficient of the row above it
    int leading_coeff = -1;
    for (int i = 0; i < rows; i++) {
        int pivot = find_row_pivot(mat, i);
        if (pivot != -1 && leading_coeff >= pivot) {
            return false;
        }
        leading_coeff = pivot;
    }
    return true;
}

bool is_reduced_row_echelon(matrix *mat) {
    if (mat == NULL) {
        return false;
    }
    // Is in row echelon form
    if (!is_row_echelon(mat)) {
        return false;
    }
    // The leading entry in each non-zero row is a 1
    for (int i = 0; i < mat->rows; i++) {
        int pivot = find_row_pivot(mat, i);
        if (pivot != -1) {
            if (get_value(mat, i, pivot) != 1) {
                return false;
            }
        }
    }
    // Each column containing a leading 1 has 0s in all other entries
    for (int i = 0; i < mat->cols; i++) {
        int pivot = find_col_pivot(mat, i, 0);
        if (get_value(mat, pivot, i) == 1) {
            for (int j = i + 1; j < mat->rows; j++) {
                if (pivot != j && get_value(mat, j, i) != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

void compute_row_echelon(matrix *mat) {
    if (mat == NULL) {
        return;
    }
    for (int i = 0; i < mat->cols; i++) {
        // Swap rows if needed
        if (get_value(mat, i, i) == 0) {
             int pivot = find_col_pivot(mat, i, i);
             if (pivot != -1 && pivot != i) {
                swap_rows(mat, pivot, i);
             }
        }
        // Multiply and subtract other rows
        for (int j = i + 1; j < mat->rows; j++) {
            double top = get_value(mat, j, i);
            double bottom = get_value(mat, i, i);
            if (bottom != 0) {
                subtract_row(mat, j, i, top / bottom);
            }
        }
    }
}

void compute_reduced_row_echelon(matrix *mat) {
    if (mat == NULL) {
        return;
    }
    compute_row_echelon(mat);
    unsigned int rows = mat->rows;
    int pivots[rows];
    for (int i = 0; i < rows; i++) {
        // Convert all pivots to ones
        pivots[i] = find_row_pivot(mat, i);
        if (pivots[i] != -1) {
            double value = get_value(mat, i, pivots[i]);
            multiply_row(mat, i, 1 / value);
        }
    }
    for (int i = rows - 1; i >= 0; i--) {
        if (pivots[i] != -1) {
            for (int j = i - 1; j >= 0; j--) {
                double value = get_value(mat, j, pivots[i]);
                subtract_row(mat, j, i, value);
            }
        }
    }
}
