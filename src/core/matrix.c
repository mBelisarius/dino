#include "src/core/matrix.h"

#include <stdio.h>
#include <stdlib.h>

Matrix* Matrix_construct(int lines, int columns)
{
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->data = malloc((lines * columns) * sizeof(int));
    matrix->rows = lines;
    matrix->columns = columns;

    return matrix;
}

void Matrix_fill(Matrix* matrix, int value)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {
            int aux = i * matrix->columns + j;
            matrix->data[aux] = value;
        }
    }
}

void Matrix_setValue(Matrix* matrix, int row, int col, int value)
{
    int pos = row * matrix->columns + col;
    matrix->data[pos] = value;
}

int Matrix_getValue(Matrix* matrix, int row, int col)
{
    int pos = row * matrix->columns + col;
    return matrix->data[pos];
}

void Matrix_printf(Matrix* matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {
            printf("%d", Matrix_getValue(matrix, i, j));
        }
        printf("\n");
    }
}
