#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "file_io.h"
#include "matrix.h"


int main() {
    Matrix *A = read_matrix("matrix1.txt");
    Matrix *B = read_matrix("matrix2.txt");
    

    if (!A || !B || A->cols != B->rows) {
        printf("Matrix dimensions incompatible or read error\n");
        return 1;
    }

    Matrix *result = create_matrix(A->rows, B->cols);
    pthread_t threads[A->rows][B->cols];

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->cols; j++) {
            ThreadArgs *args = malloc(sizeof(ThreadArgs));
            args->A = A;
            args->B = B;
            args->result = result;
            args->row = i;
            args->col = j;
            pthread_create(&threads[i][j], NULL, compute_element, args);
        }
    }

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->cols; j++) {
            pthread_join(threads[i][j], NULL);
        }
    }

    write_matrix("result.txt", result);

    free_matrix(A);
    free_matrix(B);
    free_matrix(result);
    return 0;
}
