#ifndef EVENTS_H
#define EVENTS_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

#include "../worldgen/world_gen.h"
#include "../score/score.h"

int perceive(Object *dino, int command);
int get_input();
void fill_movements();
void fill_movements_crouch();
void jump(Object *dino);
void crouch(Object *dino);

#endif
