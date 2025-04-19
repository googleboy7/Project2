#ifndef FILE_IO_H
#define FILE_IO_H

#include "matrix.h"

Matrix *read_matrix(const char *filename);
void write_matrix(const char *filename, Matrix *matrix);

#endif
