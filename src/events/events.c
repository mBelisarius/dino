#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "../worldgen/world_gen.h"
#include "events.h"

int* movements, movements_length = 6;
int movements_crouch[4], fill_movements_crouch_length = 3;
bool crouched = false, jumping = false;
char user_input;

void perceive(Object* dino, int game_matrix[6][24], int command)
{
    if (jumping)
    {
        jump(dino, movements, &movements_length);
        return;
    }

    short dinosaur_parts = 0; // keeps track of how many dinosaur parts are visible

    if (crouched)
    {
        int curr_row = dino->y;
        for (int i = 0; i < X; i++)
        {
            dinosaur_parts += (game_matrix[i][curr_row] == Dino) ? 1 : 0;
            crouch(dino, movements_crouch,&fill_movements_crouch_length);
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
        
    }

    switch (command)
    {
        case 119:
            jumping = true;
            fill_movements(movements);
            jump(dino, movements, &movements_length);

        case 115:
            crouched = true;
            fill_movements_crouch(movements_crouch);
            crouch(dino, movements_crouch, &fill_movements_crouch_length);
        
        default:
            // faz nada
            break;
    }
}

int get_input()
{
    if (_kbhit())
    {
        user_input = _getch();    
        int int_input = user_input;    
        return int_input;
    }   
    return -1;
}

void fill_movements()
{
    movements = malloc(6 * sizeof(int));
    movements_length = 6;
    int arr_copied[6] = {-2, -1, 0, 0, 1, 2};

    for (int i = 0; i < 6; i++)
    {
        movements[i] = arr_copied[i];
    }
}

void fill_movements_crouch()
{
    realloc(movements_crouch, 4 * sizeof(int));
    int arr_copied[4] = {-1,0,0,1};
    for (int i = 0; i < 4 ; i++)
    {
        movements_crouch[i] = arr_copied[i];
    }
}

void jump(Object* dino, int* movements, int* length)
{
    dino->y += movements[0];

    for (int i = 0; i < (*length)-1; i++)
    {
        movements[i] = movements[i+1];
    }

    movements = realloc(movements, ((*length)-1) * sizeof(int));

    (*length)--;

    if ((*length) == 0)
    {
        jumping = false;
        free(movements);
    }
}

void crouch(Object* dino, int* movements_crouch, int* length)
{
    dino->y += movements_crouch[0];

    for (int i = 0; i < (*length)-1; i++)
    {
        movements_crouch[i] = movements_crouch[i+1];
    }
    realloc(movements, ((*length)-1) * sizeof(int));

    (*length)--;

    if (*length == 0)
    {
       crouched = false;
    }
}
