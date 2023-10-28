#ifndef DINO_WORLDGEN_GAME_H
#define DINO_WORLDGEN_GAME_H

#include "../utils/matrix.h"

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

#endif //DINO_WORLDGEN_GAME_H
