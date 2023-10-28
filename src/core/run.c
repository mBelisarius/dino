#include "run.h"

#include "../events/events.h"
#include "../graphics/render.h"
#include "../score/score.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void run(Game* game, Object objects[game->width], Object* dino)
{
    HIDE_CURSOR();

    srand(time(NULL));
    Sleep(game->speed);

    MOVE_HOME();

    generateObject(game, objects);

    fillMatrix(game, objects, dino);

    printf("Score: %5i    |    Highest score: %5i    |    Deaths: %3i",
           game->score, getHighestScore(), getDeaths());

    ERASE_LEND();
    printf("\n");

    render(game);

    int command = get_input();
    int is_alive = perceive(game, dino, command);

    moveObjects(objects);

    if (is_alive == -1)
    {
        setHighestScore(game);
        addDeaths();
        resetWorld(game, dino);

        return;
    }

    addScore(game);

    int aux = 5 + 5 * (game->speed < 150) + 5 * (game->speed < 120)
              + 5 * (game->speed < 100) + 5 * (game->speed < 60)
              + 5 * (game->speed < 200) + 5 * (game->speed < 300);

    game->speed -= game->speed > 20 && game->score % aux == 0 ? 5 : 0;
}
