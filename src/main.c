#include <stdio.h>
#include "./worldgen/world_gen.h"

int main()
{
    printf("Hello, World!\n");
    Object dino = {4, 4, Dino};
    
    run(&dino);
    return 0;
}
