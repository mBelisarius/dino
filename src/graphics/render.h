#ifndef DINO_RENDER_RENDER_H
#define DINO_RENDER_RENDER_H

#include "frames_provisory.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/utils.h"

void print_dino(int dinos);

void print_ptero(int count);

void print_cacto(int count);

void printer(int current_int, int count_line, int dinos);

void render(int matrix[6][24]);

#endif //DINO_RENDER_RENDER_H
