#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char user_input;

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

