#ifndef EVENTS_H
#define EVENTS_H

    #include "../worldgen/world_gen.h"

    int perceive(Object* dino, int game_matrix[6][24], int command);
    int get_input();
    void fill_movements();
    void fill_movements_crouch();
    void jump(Object* dino);
    void crouch(Object* dino);

#endif
