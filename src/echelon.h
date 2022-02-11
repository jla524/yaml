#include "matrix.h"

int find_pivot(matrix *mat, int row);
bool is_row_echelon(matrix *mat);
bool is_reduced_row_echelon(matrix *mat);
void compute_row_echelon(matrix *mat);
void compute_reduced_row_echelon(matrix *mat);
