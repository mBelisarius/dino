#ifndef DINO_WORLDGEN_WORLDGEN_H
#define DINO_WORLDGEN_WORLDGEN_H

#include "../graphics/render.h"
#include "../score/score.h"
#include "../utils/matrix.h"
#include "../utils/utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys\timeb.h>
#include <time.h>
#include <Windows.h>

#define DEFAULT_OFFSET 12
#define INITIAL_TICK_SLEEP 150

#define Y 6

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

extern int obj_index;

extern int offset;

int randomInt(int min, int max);

void fillMatrix(Matrix* game, Object objects[game->columns], Object* dino);

void generateObject(Matrix* game, Object objects[game->columns]);

void moveObjects(Object objects[]);

void run(Matrix* game, Object objects[game->columns], Object* dino);

void reset(Object * dino);

#endif //DINO_WORLDGEN_WORLDGEN_H
