#include <stdio.h>
#include <stdlib.h>
#include "matrix.h" 
#include "file_io.h"
#include <string.h>

Matrix *read_matrix(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    int rows = 300, cols = 300;
    Matrix *matrix = create_matrix(rows, cols);

    char line[4096];
    int i = 0, j = 0;

    while (fgets(line, sizeof(line), file)) {
        // Skip blank lines
        if (strlen(line) <= 1) continue;

        char *token = strtok(line, " \t\r\n");
        while (token && i < rows) {
            if (j >= cols) {
                j = 0;
                i++;
                if (i >= rows) break;
            }
            int val;
            if (sscanf(token, "%d", &val) == 1) {
                matrix->data[i][j++] = val;
            }
            token = strtok(NULL, " \t\r\n");
        }
    }

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
