#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"


Matrix *create_matrix(int rows, int cols) {
    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
    if (!matrix) return NULL;

    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int **)malloc(rows * sizeof(int *));
    if (!matrix->data) {
        free(matrix);
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int *)malloc(cols * sizeof(int));
        if (!matrix->data[i]) {
            for (int j = 0; j < i; j++) free(matrix->data[j]);
            free(matrix->data);
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

void free_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++)
        free(matrix->data[i]);
    free(matrix->data);
    free(matrix);
}

void *compute_element(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg;
    int sum = 0;
    for (int k = 0; k < args->A->cols; k++) {
        sum += args->A->data[args->row][k] * args->B->data[k][args->col];
    }

    args->result->data[args->row][args->col] = sum;

    // ✅ Add this debug line:
    if (args->row < 3 && args->col < 3)  // limit output
        printf("result[%d][%d] = %d\n", args->row, args->col, sum);

    free(arg);
    return NULL;
}
