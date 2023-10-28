#ifndef DINO_CORE_GAME_H
#define DINO_CORE_GAME_H

#include "src/core/matrix.h"

#define INITIAL_TICK_SLEEP 150

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

typedef struct
{
    Matrix data;
    int width;
    int height;

    int score;
    int speed;
} Game;

Game* Game_construct(int width, int height);

void Game_clear(Game* game);

void Game_reset(Game* game);

void Game_setValue(Game* game, int row, int col, int value);

int Game_getValue(Game* game, int row, int col);

#endif //DINO_CORE_GAME_H
