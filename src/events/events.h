#ifndef DINO_EVENTS_EVENTS_H
#define DINO_EVENTS_EVENTS_H

#include "../score/score.h"
#include "../worldgen/game.h"
#include "../worldgen/worldgen.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

int perceive(Game* game, Object* dino, int command);

int get_input();

void fill_movements();

void fill_movements_crouch();

void jump(Object* dino);

void crouch(Object* dino);

#endif //DINO_EVENTS_EVENTS_H
