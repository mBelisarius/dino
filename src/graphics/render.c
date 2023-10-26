#include "render.h"


void render(int matrix[6][24])
{
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 8; j++){
            for(int k = 0; k < 24; k++){
                printer(matrix[i][k], j);
            }
            printf("\n");
        }
        
    }
}


void printer(int current_int, int count_line)
{
    switch (current_int){
    case 1:
        print_cacto(count_line);
        break;
    case 2:
        print_ptero(count_line);
        break;
    case 3:
        print_dino(count_line);
        break;
    
    default:
        printf("''''''''");
        break;
    }
}


void print_cacto(int count){
    switch (count)
    {
    case 0:
        printf("11111111");
        break;
    case 1:
        printf("11111111");
        break;
    case 2:
        printf("11111111");
        break;
    case 3:
        printf("11111111");
        break;
    case 4:
        printf("11111111");
        break;
    case 5:
        printf("11111111");
        break;
    case 6:
        printf("11111111");
        break;
    case 7:
        printf("11111111");
        break;
    }
}


void print_ptero(int count){
    switch (count)
    {
    case 0:
        printf("22222222");
        break;
    case 1:
        printf("22222222");
        break;
    case 2:
        printf("22222222");
        break;
    case 3:
        printf("22222222");
        break;
    case 4:
        printf("22222222");
        break;
    case 5:
        printf("22222222");
        break;
    case 6:
        printf("22222222");
        break;
    case 7:
        printf("22222222");
        break;
    }
}

void print_dino(int count){
    switch (count)
    {
    case 0:
        printf("33333333");
        break;
    case 1:
        printf("33333333");
        break;
    case 2:
        printf("33333333");
        break;
    case 3:
        printf("33333333");
        break;
    case 4:
        printf("33333333");
        break;
    case 5:
        printf("33333333");
        break;
    case 6:
        printf("33333333");
        break;
    case 7:
        printf("33333333");
        break;
    }
}