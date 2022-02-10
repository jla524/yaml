#include "matrix.h"

double *get_row(matrix *mat, int number);
double *get_column(matrix *mat, int number);
void swap_rows(matrix *mat, int row_a, int row_b);
void subtract_row(matrix *mat, int row_a, int row_b, double factor);
