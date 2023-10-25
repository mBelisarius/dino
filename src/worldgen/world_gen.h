#ifndef DINO_GAME_H
#define DINO_GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <sys\timeb.h>

#define DEFAULT_OFFSET 7
#define INITIAL_TICK_SLEEP 200

#define X 24
#define Y 6

typedef enum {
    Cactus = 1,
    Ptero = 2,
    Dino = 3
} Types;

typedef struct {
    int x, y;
    Types type;
} Object;

extern int game_matrix[Y][X];
extern int obj_index;
extern int offset;
extern Object objects[X];

int randomInt(int min, int max);
void printMatrix();
void fillMatrix();
void generateObject();
void moveObjects();
void run();

#endif