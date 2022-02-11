#include "matrix.h"

int find_row_pivot(matrix *mat, int row);
int find_col_pivot(matrix *mat, int col, int start);
bool is_row_echelon(matrix *mat);
bool is_reduced_row_echelon(matrix *mat);
void compute_row_echelon(matrix *mat);
void compute_reduced_row_echelon(matrix *mat);
