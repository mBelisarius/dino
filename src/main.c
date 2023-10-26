#include "./utils/utils.h"
#include "./worldgen/worldgen.h"

#include <stdio.h>

int main()
{
    configureTerminal();
    ERASE_ALL();

    Object dino = {4, 4, Dino};

    system("pause");
    while(true)
    {
        run(&dino);
    }

    return 0;
}
