#include <stdbool.h>
#include "matrix.h"

void print_matrix(matrix *mat);
bool size_equal(matrix *a, matrix *b);
bool row_valid(matrix *mat, int row);
bool col_valid(matrix *mat, int col);
unsigned int get_index(matrix *mat, int row, int col);
double get_value(matrix *mat, int row, int col);
