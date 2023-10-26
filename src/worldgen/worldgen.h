#ifndef DINO_WORLDGEN_WORLDGEN_H
#define DINO_WORLDGEN_WORLDGEN_H

#include "../graphics/render.h"
#include "../score/score.h"
#include "../utils/utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys\timeb.h>
#include <time.h>
#include <Windows.h>

#define DEFAULT_OFFSET 12
#define INITIAL_TICK_SLEEP 400

// #define X 24
// #define Y 6
#define X 24
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

extern int game_matrix[Y][X];

extern int obj_index;

extern int offset;

extern Object objects[X];

int randomInt(int min, int max);

__attribute__((unused))
void printMatrix(Object* dino);

void fillMatrix(Object* dino);

void generateObject();

void moveObjects();

void run(Object* dino);

void reset();

#endif //DINO_WORLDGEN_WORLDGEN_H
