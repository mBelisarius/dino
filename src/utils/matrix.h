#ifndef DINO_UTILS_MATRIX_H
#define DINO_UTILS_MATRIX_H


typedef struct{
    int *vector;
    int lines;
    int columns;
} Matrix;

void buildMatrix(Matrix *x);

void fillMatrix(Matrix *x, int valor);

void setPosition(Matrix *x, int i, int j, int valor); 

int getPosition(Matrix *x, int i, int j);

void showMatrix(Matrix *x);

#endif