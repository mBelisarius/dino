#include "game.h"

#include <stdlib.h>

Game* Game_construct(int width, int height)
{
    Game* game = malloc(sizeof(Game));

    game->data = *Matrix_construct(height, width);
    game->width = width;
    game->height = height;

    game->score = 0;
    game->speed = INITIAL_TICK_SLEEP;

    return game;
}

void Game_clear(Game* game)
{
    Matrix_fill(&(game->data), 0);
}

void Game_reset(Game* game)
{
    Game_clear(game);
    game->score = 0;
    game->speed = INITIAL_TICK_SLEEP;
}

int Game_getValue(Game* game, int row, int col)
{
    return Matrix_getValue(&(game->data), row, col);
}

void Game_setValue(Game* game, int row, int col, int value)
{
    Matrix_setValue(&(game->data), row, col, value);
}
