#include "src/score/score.h"

int highest_score = 0;
int deaths = 0;

void addScore(Game* game)
{
    game->score++;
}

int getHighestScore()
{
    return highest_score;
}

void setHighestScore(Game* game)
{
    if (game->score > highest_score)
    {
        highest_score = game->score;
    }
}

void addDeaths()
{
    deaths++;
}

int getDeaths()
{
    return deaths;
}
