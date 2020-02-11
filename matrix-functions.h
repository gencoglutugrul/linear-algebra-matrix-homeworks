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