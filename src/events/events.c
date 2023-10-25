#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "../worldgen/world_gen.h"

bool crouched = false;

void perceive(Object* dino, int** game_matrix, int command)
{
    short dinosaur_parts = 0; // keeps track of how many dinosaur parts are visible

    if (crouched)
    {
        int curr_row = dino->y;
        for (int i = 0; i < X; i++)
        {
            dinosaur_parts += (game_matrix[i][curr_row] == Dino) ? 1 : 0;
        }
    }
    else
    {
        for (int i = 0; i < Y; i++)
        {
            dinosaur_parts += (game_matrix[4][i] == Dino) ? 1 : 0;
        }
    }

    if (dinosaur_parts != 2)
    {
        // morreu
    }

    switch (command)
    {
        case 119:
            // função de pular
            break;

        case 115:
            // função de abaixar
            break;
        
        default:
            // faz nada
            break;
    }
}