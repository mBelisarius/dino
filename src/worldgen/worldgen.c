#include "worldgen.h"
#include "../graphics/render.h"

#include <stdio.h>
#include <stdlib.h>

// TODO: Remove global variable
int obj_index = 0, offset = DEFAULT_OFFSET;

int randomInt(int min, int max)
{
    return rand() % max + min;
}

void fillMatrix(Game* game, Object objects[game->width], Object* dino)
{
    Game_clear(game);

    // Draw the objects onto the matrix
    for (int i = 0; i < obj_index; i++)
    {
        Object curr = objects[i];

        Game_setValue(game, curr.y, curr.x, (int)curr.type);

        if (curr.type == Cactus && game->width - curr.y > 1)
        {
            for (int y = curr.y; y < game->height; y++)
            {
                Game_setValue(game, y, curr.x, (int)curr.type);
            }
        }
    }

    // Add dino to the matrix overlaying the objects
    for (int y = dino->y; y < game->height; y++)
    {
        if (Game_getValue(game, y, dino->x) == 0)
        {
            Game_setValue(game, y, dino->x, dino->type);
        }
    }
}

void generateObject(Game* game, Object objects[game->width])
{
    // Avoid objects being to close
    // Offset is controlled by the DEFAULT_OFFSET constant
    if (offset > 0)
    {
        offset--;
        return;
    }

    int type_num = randomInt(1, 100);

    // Chances: 80% cactus, 20% bird
    int percent_bird = 20;

    type_num = type_num > percent_bird ? 1 : 2;

    Types type = (Types)type_num;

    int y;
    switch (type)
    {
        case Cactus:
            y = randomInt(game->height - 3, game->height - 1);
            break;

        case Ptero:
            y = randomInt(0, game->height - 1);
            break;

        default:
            exit(1);
    }

    Object obj = { game->width - 1, y, type };

    objects[obj_index++] = obj;
    offset = DEFAULT_OFFSET;
}

void moveObjects(Object objects[])
{
    for (int i = 0; i < obj_index; i++)
    {
        objects[i].x--;

        if (objects[i].x == 0)
        {
            obj_index--;
            objects[i] = objects[obj_index];
        }
    }
}

void resetWorld(Game* game, Object* dino)
{
    ERASE_ALL();

    Game_reset(game);

    dino->y = 4;

    // Clear objects
    obj_index = 0;
}
