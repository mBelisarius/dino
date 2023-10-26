#include "score.h"

int score = 0, highest_score = 0;

void addScore()
{
    score++;
}

void highestScore()
{
    if (score > highest_score)
    {
        highest_score = score;
    }
}
