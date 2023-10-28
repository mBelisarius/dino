#include "events.h"

int movements[6], movements_length = 6;
int movements_crouch[5], crouch_len;
bool crouched = false, jumping = false;
char user_input;

int perceive(Matrix* game_matrix, Object* dino, int command)
{
    // keeps track of how many dinosaur parts are visible
    short dinosaur_parts = 0;

    if (crouched)
    {
        for (int x = 0; x < X; x++)
        {
            dinosaur_parts += (Matrix_getValue(game_matrix, dino->y, x) == (int)Dino) ? 1 : 0;
        }
    }
    else
    {
        for (int y = 0; y < Y; y++)
        {
            dinosaur_parts += (Matrix_getValue(game_matrix, y, 4) == (int)Dino) ? 1 : 0;
        }
    }

    if (dinosaur_parts < 2 && !crouched)
    {
        reset(dino);
        return -1; // dead
    }

    if (dinosaur_parts == 0 && crouched)
    {
        reset(dino);
        return -1; // dead
    }

    if (jumping)
    {
        jump(dino);
        return 0;
    }

    if (crouched)
    {
        crouch(dino);
        return 0;
    }

    switch (command)
    {
        case 119:
            jumping = true;
            fill_movements();
            jump(dino);
            break;

        case 115:
            crouched = true;
            fill_movements_crouch();
            crouch(dino);
            break;

        default:
            break;
    }

    return 0; // alive
}

int get_input()
{
    if (_kbhit())
    {

        user_input = (char)_getch();

        if (crouched || jumping)
        {
            return -1;
        }

        int int_input = (int)user_input;
        return int_input;
    }

    return -1;
}

void fill_movements()
{
    int arr_copied[] = { -2, -1, 0, 0, 1, 2 };

    for (int i = 0; i < 6; i++)
    {
        movements[i] = arr_copied[i];
    }
    movements_length = 6;
}

void fill_movements_crouch()
{
    crouch_len = 5;

    int arr_copied[] = { 1, 0, 0, 0, -1 };

    for (int i = 0; i < crouch_len; i++)
    {
        movements_crouch[i] = arr_copied[i];
    }
}

void jump(Object* dino)
{
    dino->y += movements[0];

    for (int i = 0; i < movements_length - 1; i++)
    {
        movements[i] = movements[i + 1];
    }

    movements_length--;
    if (movements_length == 0)
    {
        jumping = false;
    }
}

void crouch(Object* dino)
{
    dino->y += movements_crouch[0];

    for (int i = 0; i < crouch_len - 1; i++)
    {
        movements_crouch[i] = movements_crouch[i + 1];
    }

    crouch_len--;

    if (crouch_len == 0)
    {
        crouched = false;
    }
}
