#include <stdio.h>
#include "./worldgen/world_gen.h"
#include "./utils/utils.h"

int main()
{
    configureTerminal();
    ERASE_ALL();
    Object dino = {4, 4, Dino};

    system("cls");
    for (;;)
    {
        run(&dino);
    }

    return 0;
}
