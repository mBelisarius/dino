#ifndef DINO_RENDER_RENDER_H
#define DINO_RENDER_RENDER_H

#include "src/core/game.h"
#include "src/graphics/frames_provisory.h"
#include "src/utils/utils.h"

void print_dino(int dinos);

void print_ptero(int count);

void print_cacto(int count);

void printer(int object, int count_line, int dinos);

void render(Game* game);

#endif //DINO_RENDER_RENDER_H
