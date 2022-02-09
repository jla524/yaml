#include "matrix.h"

matrix *fill(matrix *mat, double val);
matrix *zeros(unsigned int rows, unsigned int cols);
matrix *ones(unsigned int rows, unsigned int cols);
matrix *rands(unsigned int rows, unsigned int cols);
matrix *identity(unsigned int n);
matrix *copy(matrix *source);
matrix *from_file(char *path);
