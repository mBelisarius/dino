#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <stdio.h>

int main()
{
    const char* filename = "../assets/dino1.png";
    int width, height, channels;
    unsigned char* image = stbi_load(filename, &width, &height, &channels, STBI_rgb);
    int dino1[8][16];

    if (image == NULL)
    {
        printf("Erro ao carregar a imagem.\n");
        return -1;
    }

    // Limiar (ajuste conforme necessário)
    int threshold = 128;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // 3 canais (STBI_rgb)
            int index = (x + y * width) * 3;
            unsigned char r = image[index];
            unsigned char g = image[index + 1];
            unsigned char b = image[index + 2];

            // Converter para escala de cinza
            unsigned char pixel = (r + g + b) / 3;

            // Valor abaixo do limiar: se o RGB do pixel for igual a da cor
            // BRANCA armazena 1
            //
            // Valor acima do limiar: se o RGB do pixel for igual a da cor
            // PRETA armazena 0
            if (pixel < threshold)
            {
                dino1[x][y] = 0;
            }
            else
            {
                dino1[x][y] = 1;
            }
        }
    }

    stbi_image_free(image);

    //print matriz dino
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (dino1[x][y] == 1)
            {
                printf("  ");
            }
            else
            {
                printf("%i ", dino1[x][y]);
            }
        }

        printf("\n");
    }

    return 0;
}
