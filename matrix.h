#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

typedef struct {
    Matrix *A;
    Matrix *B;
    Matrix *result;
    int row;
    int col;
} ThreadArgs;

Matrix *create_matrix(int rows, int cols);
void free_matrix(Matrix *matrix);
void *compute_element(void *arg);

#endif
