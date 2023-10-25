#include <stdio.h> //struct armazena vetor qtd de llinhas e colunas
//funcao p pegar o indice dele
#include <stdlib.h>

typedef struct{
    int *vector;
    int lines;
    int columns;
} Matrix;

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

int main()
{
    int matrix[3][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Matrix vetor;
    vetor.lines = 3;
    vetor.columns = 3;

    buildMatrix(&vetor);
    fillMatrix(&vetor, 0);
    showMatrix(&vetor);

    setPosition(&vetor, 1,1,16);
    showMatrix(&vetor);

    getPosition(&vetor, 1, 1);

    free(vetor.vector);
 
    return 0;
}