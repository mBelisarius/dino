#include "utils.h"

#include <Windows.h>

void configureTerminal()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;

    GetConsoleMode(handle, &mode);
    mode |= TERMINAL_PROCESSING;

    SetConsoleMode(handle, mode);
}
