#include <time.h>
#include <stdlib.h>
#define MAX_SIZE_OF_MATRIX 50

struct Matrix {
    int column_size;
    int row_size;
    int data[MAX_SIZE_OF_MATRIX][MAX_SIZE_OF_MATRIX];
};

typedef struct Matrix Matrix;

Matrix* create_matrix(int column, int row) {
    struct Matrix* matrix = malloc(sizeof(Matrix));
    matrix->row_size = row;
    matrix->column_size = column;
    return matrix;
}

Matrix* create_random_matrix(int column, int row, int max, int min){
    srand(time(0));

    struct Matrix* matrix = create_matrix(column, row);
    for(int i=0; i<column; i++){
        for(int j=0; j<row; j++){
            matrix->data[i][j] = min + rand() / (RAND_MAX / (max - min + 1) + 1); 
        }
    }
    return matrix;
}

void print_matrix(Matrix* matrix){
    for(int i=0; i<matrix->column_size; i++){
        printf("|");
        for(int j=0; j<matrix->row_size; j++){
            printf(" %d ",matrix->data[i][j]);
        }
        printf("|\n");
    }
}
