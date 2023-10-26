#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "../worldgen/world_gen.h"
#include "events.h"

int movements[6], movements_length = 6;
int movements_crouch[4], fill_movements_crouch_length = 3;
bool crouched = false, jumping = false;
char user_input;

int perceive(Object* dino, int command)
{
    if (jumping)
    {
        jump(dino);
        return 0;
    }

    short dinosaur_parts = 0; // keeps track of how many dinosaur parts are visible

    if (crouched)
    {
        int curr_row = dino->y;
        for (int i = 0; i < X; i++)
        {
            dinosaur_parts += (game_matrix[curr_row][i] == (int)Dino) ? 1 : 0;
            crouch(dino);
        }
    }
    else
    {
        for (int i = 0; i < Y; i++)
        {
            dinosaur_parts += (game_matrix[i][4] == (int)Dino) ? 1 : 0;
        }
    }

    if (dinosaur_parts != 2)
    {
        return -1; // dead
    }

    switch (command)
    {
        case 119:
            jumping = true;
            fill_movements();
            jump(dino);

        case 115:
            crouched = true;
            fill_movements_crouch();
            crouch(dino);
        
        default:
            // faz nada
            break;
    }

    return 0; // alive
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
    int arr_copied[6] = {-2, -1, 0, 0, 1, 2};

    for (int i = 0; i < 6; i++)
    {
        movements[i] = arr_copied[i];
    }
    movements_length = 6;
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

void jump(Object* dino)
{
    dino->y += movements[0];

    for (int i = 0; i < movements_length-1; i++)
    {
        movements[i] = movements[i+1];
    }

    movements_length--;
    if (movements_length == -1)
    {
        jumping = false;
    }
}

void crouch(Object* dino)
{
    dino->y += movements_crouch[0];

    for (int i = 0; i < fill_movements_crouch_length-1; i++)
    {
        movements_crouch[i] = movements_crouch[i+1];
    }
    realloc(movements, (fill_movements_crouch_length-1) * sizeof(int));

    fill_movements_crouch_length--;

    if (fill_movements_crouch_length == 0)
    {
       crouched = false;
    }
}
