#include <stdlib.h>
#include "echelon.h"
#include "helpers.h"

int find_pivot(matrix *mat, int row) {
    if (mat == NULL || !row_valid(mat, row)) {
        return -1;
    }
    int j = row;
    while (j < mat->cols && get_value(mat, row, j) != 0) {
        j++;
    }
    return col_valid(mat, j) ? j : -1;
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
        int pivot = find_pivot(mat, i);
        if (leading_coeff >= pivot) {
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
    // Each column containing a leading 1 has zeros in all other entries
    for (int i = 0; i < mat->rows; i++) {
        int pivot = find_pivot(mat, i);
        if (pivot != -1) {
            if (get_value(mat, i, pivot) != 1) {
                return false;
            }
            for (int j = i + 1; j < mat->cols; j++) {
                if (j != pivot && get_value(mat, i, j) != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

void compute_row_echelon(matrix *mat);
void compute_reduced_row_echelon(matrix *mat);
