#include "src/core/game.h"
#include "src/utils/utils.h"
#include "src/worldgen/worldgen.h"

#include <stdio.h>
#include <stdlib.h>

char text_buffer[8192];

int main()
{
    setvbuf(stdout, text_buffer, _IOFBF, sizeof(text_buffer));
    configureTerminal();
    ERASE_ALL();

    Game* game_matrix = Game_construct(24, 6);
    Object objects[24];
    Object dino = {4, 4, Dino};

    system("pause");
    while(true)
    {
        run(game_matrix, objects, &dino);
    }

    return 0;
}
