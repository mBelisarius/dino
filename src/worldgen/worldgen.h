#ifndef DINO_WORLDGEN_WORLDGEN_H
#define DINO_WORLDGEN_WORLDGEN_H

#include "../core/game.h"

#define DEFAULT_OFFSET 12

// TODO: Remove global variable
extern int obj_index;

// TODO: Remove global variable
extern int offset;

int randomInt(int min, int max);

void fillMatrix(Game* game, Object objects[game->width], Object* dino);

void generateObject(Game* game, Object objects[game->width]);

void moveObjects(Object objects[]);

void run(Game* game, Object objects[game->width], Object* dino);

void resetWorld(Game* game, Object* dino);

#endif //DINO_WORLDGEN_WORLDGEN_H
