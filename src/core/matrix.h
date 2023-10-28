#ifndef DINO_CORE_MATRIX_H
#define DINO_CORE_MATRIX_H

typedef struct
{
    int* data;
    int rows;
    int columns;
} Matrix;

Matrix* Matrix_construct(int lines, int columns);

void Matrix_fill(Matrix* matrix, int value);

void Matrix_setValue(Matrix* matrix, int row, int col, int value);

int Matrix_getValue(Matrix* matrix, int row, int col);

void Matrix_printf(Matrix* matrix);

#endif //DINO_CORE_MATRIX_H
