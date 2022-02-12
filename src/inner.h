#include "matrix.h"

double *get_row(matrix *mat, int number);
double *get_column(matrix *mat, int number);
void swap_rows(matrix *mat, int row_a, int row_b);
void multiply_row(matrix *mat, int row, double factor);
void subtract_row(matrix *mat, int row_a, int row_b, double factor);
matrix *insert_row(matrix *a, matrix *b, int number);
matrix *insert_col(matrix *a, matrix *b, int number);
matrix *remove_row(matrix *mat, int number);
matrix *remove_col(matrix *mat, int number);
