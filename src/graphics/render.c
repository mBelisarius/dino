#include <stdio.h>
#include <stdlib.h>


void render(int matrix[6][24])
{
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 24; j++){
            for(int k = 0; k < 8; k++){
                printer(matrix[i][j], k);
                printf("\n");
            }
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
        printf("00000000");
        break;
    }
}


void print_cacto(int count){

}


void print_ptero(int count){

}

void print_dino(int count){

}