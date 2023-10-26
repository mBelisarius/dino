#define STB_IMAGE_IMPLEMENTATION
#include <stdio.h>
#include "stb_image.h"

//DINO1

int main() {
    const char* filename = "dino1.png";
    int width, height, channels;
    unsigned char* image = stbi_load(filename, &width, &height, &channels, STBI_rgb);
    int dino1[8][16];

    if (image != NULL) {
        int threshold = 128; // Limiar (ajuste conforme necessário)

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int index = (x + y * width) * 3; // 3 canais (STBI_rgb)
                unsigned char r = image[index];
                unsigned char g = image[index + 1];
                unsigned char b = image[index + 2];
                unsigned char pixel = (r + g + b) / 3; // Converter para escala de cinza

                if (pixel < threshold) {
                    dino1[x][y] = 0; // Se o RGB do pixel for igual a da cor BRANCA armazena 1 na matriz
                                    // Valor abaixo do limiar
                } else {
                    dino1[x][y] = 1; // Se o RGB do pixel for igual a da cor PRETA armazena 0 na matriz
                                    // Valor acima do limiar
                }
            }
            
        }

        // Libere a memória alocada para a imagem
        stbi_image_free(image);
    } else {
        printf("Erro ao carregar a imagem.\n");
    }



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