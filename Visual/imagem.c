#define STB_IMAGE_IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#include "stb_image.h"
#include "frames.h"

//DINO1
int gerarMatrizImagem(char *imagem, char file[]){
    const char* filename = imagem;
    int width, height, channels;
    unsigned char* image = stbi_load(filename, &width, &height, &channels, STBI_rgb);
    int matriz_imagem[8][24];

    FILE * arq = fopen( file, "w");

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
                    matriz_imagem[x][y] = 0; // Se o RGB do pixel for igual a da cor BRANCA armazena 1 na matriz
                                    // Valor abaixo do limiar
                } else {
                    matriz_imagem[x][y] = 1; // Se o RGB do pixel for igual a da cor PRETA armazena 0 na matriz
                                    // Valor acima do limiar
                }
            }
            
        }

         for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if(matriz_imagem[x][y] == 0) {
                    fprintf(arq,"#");
                }
                else{
                    fprintf(arq,".");
                }
            }
            fprintf(arq,"\n");
        }
            
        // Libere a memória alocada para a imagem
        stbi_image_free(image);
    } else {
        printf("Erro ao carregar a imagem.\n");
    }
}


int main() {
    
    int dino1 = gerarMatrizImagem("obstaculo-predio-grande.png", "obstacles_big_building.txt");

    printf("%s", dino_run_1);
    printf("%s", dino_run_2);
    printf("%s", dino_crouch);
    printf("%s", obstacles_big_building);
    
    
  
    return 0;
}