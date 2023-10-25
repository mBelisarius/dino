#define STB_IMAGE_IMPLEMENTATION
#include <stdio.h>
#include "stb_image.h"

int main() {
    const char* filename = "dino.png";
    int width, height, channels;
    unsigned char* image = stbi_load(filename, &width, &height, &channels, STBI_rgb);

    if (image != NULL) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int index = (x + y * width) * 3; // 3 canais (STBI_rgb)
                unsigned char r = image[index];
                unsigned char g = image[index + 1];
                unsigned char b = image[index + 2];

                // Faça o processamento do pixel aqui
                // Por exemplo, você pode imprimir os valores de cada canal (r, g, b)
                printf("Pixel (%d, %d): R=%d, G=%d, B=%d\n", x, y, r, g, b);
            }
        }

        // Libere a memória alocada para a imagem
        stbi_image_free(image);
    } else {
        printf("Erro ao carregar a imagem.\n");
    }

    return 0;
}