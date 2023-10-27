#include "./utils/utils.h"
#include "./worldgen/worldgen.h"

#include <stdio.h>
#include <stdbool.h>

char text_buffer[8192];

int main()
{
    setvbuf(stdout, text_buffer, _IOFBF, sizeof(text_buffer));
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
