#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void buildMatrix(Matrix *x){
    x->vector = malloc((x->lines * x->columns) * sizeof(int));
}

void fillMatrix(Matrix *x, int valor){
    for (int i = 0; i < x->lines; i++)
    {

        for (int j = 0; j < x->columns; j++)
        {
            int aux = i * x->columns + j;
            x->vector[aux] = valor;
        }
    }
}

void setPosition(Matrix *x, int i, int j, int valor){
    int aux = i * x->columns + j;

    x->vector[aux] = valor;
}
int getPosition(Matrix *x, int i, int j){
    int aux = i * x->columns + j;

    return x->vector[aux];
}

void showMatrix(Matrix *x){
    for (int i = 0; i < x->lines; i++)
    {

        for (int j = 0; j < x->columns; j++)
        {
            printf("%d", getPosition(x, i, j));
        }
        printf("\n");
    }
}