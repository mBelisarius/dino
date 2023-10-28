#ifndef DINO_WORLDGEN_WORLDGEN_H
#define DINO_WORLDGEN_WORLDGEN_H

#include "./game.h"
#include "../graphics/render.h"
#include "../utils/utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys\timeb.h>
#include <time.h>
#include <Windows.h>

#define DEFAULT_OFFSET 12

extern int obj_index;

extern int offset;

typedef enum
{
    Cactus = 1,
    Ptero = 2,
    Dino = 3
} Types;

typedef struct
{
    int x, y;
    Types type;
} Object;

int randomInt(int min, int max);

void fillMatrix(Game* game, Object objects[game->width], Object* dino);

void generateObject(Game* game, Object objects[game->width]);

void moveObjects(Object objects[]);

void run(Game* game, Object objects[game->width], Object* dino);

void reset(Game* game, Object* dino);

#endif //DINO_WORLDGEN_WORLDGEN_H
