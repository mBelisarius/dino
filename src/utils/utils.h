#ifndef DINO_UTILS_UTILS_H
#define DINO_UTILS_UTILS_H

#include <Windows.h>

#define TERMINAL_PROCESSING 0x0004

#define SAVE_CURSOR() printf("\e7")

#define LOAD_CURSOR() printf("\e8")

#define ERASE_LEND() printf("\e[0K")

#define ERASE_ALL() printf("\e[2J")

#define MOVE_HOME() printf("\e[H")

#define HIDE_CURSOR() printf("\e[?25l")

#define SHOW_CURSOR() printf("\e[?25h")

#define SET_COLOR

#define MOVE_DOWN(l) printf("\e[" l "B")

#define MOVE_UP(l) printf("\e[" l "A")

void configureTerminal();

#endif //DINO_UTILS_UTILS_H
