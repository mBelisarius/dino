#include "render.h"

void render(int matrix[6][24])
{
    int dinos = 0;

    //BACKGROUND_COLOR(255, 255, 255);

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 24; k++)
            {
                printer(matrix[i][k], j, dinos);

                if (matrix[i][k] == 3)
                    dinos++;
            }
            printf("\n");
        }
    }

    fflush(stdout);
}

void printer(int current_int, int count_line, int dinos)
{
    switch (current_int)
    {
        case 1:
            //Color Teste FOREGROUND_COLOR(r, g ,b)
            FOREGROUND_COLOR(0, 255, 0);
            print_cacto(count_line);
            RESET_FOREGROUND();
            break;
        case 2:
            print_ptero(count_line);
            RESET_FOREGROUND();
            break;
        case 3:
            print_dino(dinos);
            RESET_FOREGROUND();
            break;
        default:
            printf("''''''''");
            //printf("        ");
            break;
    }
}

void print_cacto(int count)
{
    switch (count)
    {
        case 0:
            printf("11111111");
            break;
        case 1:
            printf("11111111");
            break;
        case 2:
            printf("11111111");
            break;
        case 3:
            printf("11111111");
            break;
        case 4:
            printf("11111111");
            break;
        case 5:
            printf("11111111");
            break;
        case 6:
            printf("11111111");
            break;
        case 7:
            printf("11111111");
            break;
    }
}

void print_ptero(int count)
{
    switch (count)
    {
        case 0:
            printf(PLANE_FRAME01);
            break;
        case 1:
            printf(PLANE_FRAME02);
            break;
        case 2:
            printf(PLANE_FRAME03);
            break;
        case 3:
            printf(PLANE_FRAME04);
            break;
        case 4:
            printf(PLANE_FRAME05);
            break;
        case 5:
            printf(PLANE_FRAME06);
            break;
        case 6:
            printf(PLANE_FRAME07);
            break;
        case 7:
            printf(PLANE_FRAME08);
            break;
    }
}

void print_dino(int dinos)
{
    switch (dinos)
    {
        case 0:
            printf("%s", DINO_FRAME1_LINE00);
            break;
        case 1:
            printf("%s", DINO_FRAME1_LINE01);
            break;
        case 2:
            printf("%s", DINO_FRAME1_LINE02);
            break;
        case 3:
            printf("%s", DINO_FRAME1_LINE03);
            break;
        case 4:
            printf("%s", DINO_FRAME1_LINE04);
            break;
        case 5:
            printf("%s", DINO_FRAME1_LINE05);
            break;
        case 6:
            printf("%s", DINO_FRAME1_LINE06);
            break;
        case 7:
            printf("%s", DINO_FRAME1_LINE07);
            break;
        case 8:
            printf("%s", DINO_FRAME1_LINE08);
            break;
        case 9:
            printf("%s", DINO_FRAME1_LINE09);
            break;
        case 10:
            printf("%s", DINO_FRAME1_LINE10);
            break;
        case 11:
            printf("%s", DINO_FRAME1_LINE11);
            break;
        case 12:
            printf("%s", DINO_FRAME1_LINE12);
            break;
        case 13:
            printf("%s", DINO_FRAME1_LINE13);
            break;
        case 14:
            printf("%s", DINO_FRAME1_LINE14);
            break;
        case 15:
            printf("%s", DINO_FRAME1_LINE15);
            break;
    }
}
