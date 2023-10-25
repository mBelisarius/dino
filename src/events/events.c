#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void)
{
    char ch;
    printf("Press 'q' to exit prom program\n");
    do{
        ch = _getch();
        printf("%c (%d)\n", ch, ch);
    } while( ch != 'q');
}