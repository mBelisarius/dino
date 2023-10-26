#ifndef EVENTS_H
#define EVENTS_H

    #include "../worldgen/world_gen.h"

    void perceive(Object* dino, int** game_matrix, int command);
    int get_input();
    void fill_movements(int* movements);
    void jump(Object* dino, int* movements, unsigned* length);
    void addScore();
    void highestScore();

#endif
