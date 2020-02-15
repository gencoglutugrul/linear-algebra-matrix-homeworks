#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

struct Matrix {
    size_t column_size;
    size_t row_size;
    int** data;
};

typedef struct Matrix Matrix;

Matrix* create_matrix(size_t column, size_t row) {
    struct Matrix* matrix = malloc(sizeof(Matrix));
    matrix->row_size = row;
    matrix->column_size = column;

    int **data = (int **)malloc(column * sizeof(int *));
    for(int i = 0; i < column; i++)
        data[i] = malloc(sizeof(int)*row);
    

    matrix->data=data;
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

/**
 * Usage example:
 * create_user_defined_matrix(5, 2, "Please enter value of %d. column %d row: ");
 */ 
Matrix* create_user_defined_matrix(int column, int row, char* value_request_sting){
    Matrix* matrix=create_matrix(column,row);
    for(int i=0; i<column; i++){
        for (int j=0; j<row; j++){
            printf(value_request_sting,i,j);
            scanf("%d",&matrix->data[i][j]);
        }
    }    
    return matrix;
}

int getLetterLength(int num){
    return snprintf(NULL, 0, "%i", num);
}

int getMaxSizeOfMatrixValue(Matrix* matrix){
    
    int max=matrix->data[0][0];
    int min=matrix->data[0][0];
    for(int i=0; i<matrix->column_size; i++){
        for(int j=0; j<matrix->row_size; j++){
            if(matrix->data[i][j]<min)
                min=matrix->data[i][j];
            if(matrix->data[i][j]>max)
                max=matrix->data[i][j];
        }
    }
    
    if(min<0){
        min=-10*min;
        
        if(min>max)
            return getLetterLength(-min);
        else
            return getLetterLength(max);
    }else {
        return getLetterLength(max);
    }
    
    
}

char* chrRepeat(char letter, size_t times){
    if(times==0) return "";
    char* repeated = malloc(sizeof(char)*times);
    for(int i=0; i<times; i++){
        repeated[i]=letter;
    }
    return repeated;
}

Matrix* getMainDiagonal(Matrix* matrix){
    if(matrix->column_size != matrix->row_size) 
        return NULL;

    Matrix* mainDiagonalVector=create_matrix(matrix->column_size, 1);
    
    for(int i=0; i<matrix->column_size; i++)
        mainDiagonalVector->data[i][0]=matrix->data[i][i];

    return mainDiagonalVector;
}

Matrix* sumOfMatrices(Matrix* A,Matrix* B){
    if(A->column_size != B->column_size || A->row_size != B->row_size)
        return NULL;
    
    Matrix* sum=create_matrix(A->column_size, A->row_size);
    for (int i=0; i < A->column_size; i++)
        for(int j=0; j < A->row_size; j++)
            sum->data[i][j] = A->data[i][j] + B->data[i][j];
    return sum;
}


Matrix* differenceOfMatrices(Matrix* A, Matrix* B){
    if(A->column_size != B->column_size || A->row_size != B->row_size)
        return NULL;
    
    Matrix* diff=create_matrix(A->column_size, A->row_size);
    for (int i=0; i < A->column_size; i++)
        for(int j=0; j < A->row_size; j++)
            diff->data[i][j] = A->data[i][j] - B->data[i][j];
    return diff;
}

Matrix* scalarProductOfMatrix(int scalar, Matrix* matrix){
    Matrix* newMatrix=create_matrix(matrix->column_size, matrix->row_size);
    for(int i=0; i<matrix->column_size; i++)
        for(int j=0; j<matrix->row_size; j++)
            newMatrix->data[i][j] = scalar*matrix->data[i][j];
    return newMatrix;
}

bool isZeroVector(Matrix* vector){
    for(int i=0; i<vector->column_size; i++)
        if(vector->data[i][0] != 0)
            return false;

    return true;
}

Matrix* getTransposeOfMatrix(Matrix* matrix){
    Matrix* transposed=create_matrix(matrix->row_size, matrix->column_size);
    for(int i=0; i<matrix->column_size; i++)
        for(int j=0; j<matrix->row_size; j++)
            transposed->data[j][i]=matrix->data[i][j];

    return transposed;
}

void print_matrix(Matrix* matrix){
    int maxSize=getMaxSizeOfMatrixValue(matrix);
    for(int i=0; i<matrix->column_size; i++){
        printf("|");
        for(int j=0; j<matrix->row_size; j++){
            unsigned int spaceAdjust = maxSize - getLetterLength(matrix->data[i][j]); 
            printf(" %s%d ",chrRepeat(' ',spaceAdjust),matrix->data[i][j]);
        }
        printf("|\n");
    }
}
