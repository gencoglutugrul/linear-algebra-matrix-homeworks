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
        min=-min;
    }
    if(min>max)
        return getLetterLength(-min);
    else
        return getLetterLength(max);
}

char* chrRepeat(char letter, size_t times){
    if(times==0) return "";
    char* repeated = malloc(sizeof(char)*times);
    for(int i=0; i<times; i++){
        repeated[i]=letter;
    }
    return repeated;
}

void print_matrix(Matrix* matrix){
    int maxSize=getMaxSizeOfMatrixValue(matrix);

    for(int i=0; i<matrix->column_size; i++){
        printf("|");
        for(int j=0; j<matrix->row_size; j++){
            int spaceAdjust = maxSize - getLetterLength(matrix->data[i][j]); 
            printf(" %s%d ",chrRepeat(' ',spaceAdjust),matrix->data[i][j]);
        }
        printf("|\n");
    }
}
