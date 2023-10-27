#include "score.h"

int score = 0, highscore = 0;

void addScore()
{
    score++;
}

void highestScore()
{
    if (score > highscore)
    {
        highscore = score;
    }
}
