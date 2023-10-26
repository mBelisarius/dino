#ifndef EVENTS_H
#define EVENTS_H

    #include "../worldgen/world_gen.h"

    void perceive(Object* dino, int game_matrix[6][24], int command);
    int get_input();
    void fill_movements();
    void fill_movements_crouch();
    void jump(Object* dino, int* movements, int* length);
    void crouch(Object* dino, int* movements, int* length);

#endif
