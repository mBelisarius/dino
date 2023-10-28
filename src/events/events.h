#ifndef DINO_EVENTS_EVENTS_H
#define DINO_EVENTS_EVENTS_H

#include "../worldgen/game.h"
#include "../worldgen/worldgen.h"

int perceive(Game* game, Object* dino, int command);

int get_input();

void fill_movements();

void fill_movements_crouch();

void jump(Object* dino);

void crouch(Object* dino);

#endif //DINO_EVENTS_EVENTS_H
