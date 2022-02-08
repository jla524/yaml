// https://github.com/nomemory/neat-matrix-library
#include <stdbool.h>

typedef struct matrix_s {
    unsigned int rows;
    unsigned int cols;
    double *data;
} matrix;

matrix *matrix_new(unsigned int rows, unsigned int cols);
void matrix_free(matrix *mat);
bool is_square(matrix *mat);
