#include "worldgen.h"
#include "../events/events.h"
#include "../utils/matrix.h"

int obj_index = 0, offset = DEFAULT_OFFSET, deaths = 0;
int speed = INITIAL_TICK_SLEEP;
int current_score = 0, user_highscore = 0;

Object objects[X];

int randomInt(int min, int max)
{
    return rand() % max + min;
}

void fillMatrix(Matrix* game_matrix, Object* dino)
{
    Matrix_fill(game_matrix, 0);

    // Draw the objects onto the matrix
    for (int i = 0; i < obj_index; i++)
    {
        Object curr = objects[i];

        Matrix_setValue(game_matrix, curr.y, curr.x, (int)curr.type);

        if (curr.type == Cactus && Y - curr.y > 1)
        {
            for (int y = curr.y; y < Y; y++)
            {
                Matrix_setValue(game_matrix, y, curr.x, (int)curr.type);
            }
        }
    }

    // Add dino to the matrix overlaying the objects
    for (int y = dino->y; y < Y; y++)
    {
        if (Matrix_getValue(game_matrix, y, dino->x) == 0)
        {
            Matrix_setValue(game_matrix, y, dino->x, dino->type);
        }
    }
}

void generateObject()
{
    // Avoid objects being to close
    // Offset is controlled by the DEFAULT_OFFSET constant
    if (offset > 0)
    {
        offset--;
        return;
    }

    int type_num = randomInt(1, 100);

    // Chances: 80% cactus, 20% bird
    int percent_bird = 20;

    type_num = type_num > percent_bird ? 1 : 2;

    Types type = (Types)type_num;

    int y;
    switch (type)
    {
        case Cactus:
            y = randomInt(Y - 3, Y - 1);
            break;

        case Ptero:
            y = randomInt(0, Y - 1);
            break;

        default:
            exit(1);
    }

    Object obj = { X - 1, y, type };

    objects[obj_index++] = obj;
    offset = DEFAULT_OFFSET;
}

void moveObjects()
{
    for (int i = 0; i < obj_index; i++)
    {
        objects[i].x--;

        if (objects[i].x == 0)
        {
            obj_index--;

            objects[i] = objects[obj_index];
        }
    }
}

void reset(Object * dino)
{
    ERASE_ALL();

    speed = INITIAL_TICK_SLEEP;
    score = 0;

    dino->y = 4;

    // Clear objects
    obj_index = 0;
}

void run(Matrix* game_matrix, Object *dino)
{
    HIDE_CURSOR();

    srand(time(NULL));
    Sleep(speed);

    MOVE_HOME();

    generateObject();

    fillMatrix(game_matrix, dino);
    // printMatrix();

    printf("Score: %d    |    High Score: %d    |    Deaths: %d", current_score, user_highscore, deaths);
    ERASE_LEND();
    printf("\n");

    render(game_matrix);

    int command = get_input();
    int is_alive = perceive(game_matrix, dino, command);

    moveObjects();
    //addScore();
    current_score++;

    if (is_alive == -1)
    {
        if (user_highscore < current_score) {
            user_highscore = current_score;
        }

        current_score = 0;
        deaths++;
        return;
    }

    int aux = 5 + 5 * (speed < 150) + 5 * (speed < 120) + 5 * (speed < 100) + 5 * (speed < 60) + 5 * (speed < 200) + 5 * (speed < 300);
    speed -= speed > 20 && current_score % aux == 0 ? 5 : 0;
}
