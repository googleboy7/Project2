#include <stdio.h>
#include <stdlib.h>
#include "file_io.h"

Matrix *read_matrix(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return NULL;

    int rows = 300, cols = 300;
    Matrix *matrix = create_matrix(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            fscanf(file, "%d", &matrix->data[i][j]);

    fclose(file);
    return matrix;
}

void write_matrix(const char *filename, Matrix *matrix) {
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++)
            fprintf(file, "%d ", matrix->data[i][j]);
        fprintf(file, "\n");
    }
    fclose(file);
}
