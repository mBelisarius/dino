#ifndef DINO_SCORE_SCORE_H
#define DINO_SCORE_SCORE_H

#include "src/core/game.h"

extern int highest_score;

extern int deaths;

void addScore(Game* game);

int getHighestScore();

void setHighestScore(Game* game);

void addDeaths();

int getDeaths();

#endif //DINO_SCORE_SCORE_H
