#include <stdio.h>
#include "./worldgen/world_gen.h"
#include "./utils/utils.h"

int main()
{
    configureTerminal();

    ERASE_ALL();

    printf("Hello, World!\n");
    Object dino = {4, 4, Dino};

    run(&dino);
    return 0;
}
