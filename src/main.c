#include "./utils/matrix.h"
#include "./utils/utils.h"
#include "./worldgen/worldgen.h"

#include <stdbool.h>
#include <stdio.h>

char text_buffer[8192];

int main()
{
    setvbuf(stdout, text_buffer, _IOFBF, sizeof(text_buffer));
    configureTerminal();
    ERASE_ALL();

    Matrix* game_matrix = Matrix_construct(6, 24);
    Object objects[24];
    Object dino = {4, 4, Dino};

    system("pause");
    while(true)
    {
        run(game_matrix, objects, &dino);
    }

    return 0;
}
