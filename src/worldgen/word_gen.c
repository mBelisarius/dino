#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <sys\timeb.h>

#define X 24
#define Y 6
// #define X 100
// #define Y 50

typedef enum {
    Cactus = 1,
    Ptero = 2
} Types;

typedef struct {
    int x, y;
    Types type;
} Object;

//Dinos


int game_matrix[Y][X];

int obj_index = 0;

Object objects[1024];



int generateNumber(int min, int max){
    struct timeb t;
    ftime(&t);

    srand(t.millitm);

    return rand() % max + min;
}

void printMatrix(){
    for (int i = 0; i < Y; i++){
        for (int j = 0; j < X; j++){
            printf("%d", game_matrix[i][j]);
        }
        printf("\n");
    }
}

void fillMatrix() {
    for (int i = 0; i < Y; i++){
        for (int j = 0; j < X; j++){
            game_matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < obj_index; i++){
        game_matrix[objects[i].y][objects[i].x] = (int)objects[i].type;
    }
}

void generateObject() {    
    Types type = (Types)generateNumber(1, 2);

    int y;

    switch (type) {
        case Cactus:
            break;

        case Ptero:
            break;
    }


    int y = generateNumber(0, Y-1);

    
    Object obj = {X-1, y, type};

    objects[obj_index++] = obj;        
}


void moveObjects() {
    for (int i = 0; i < obj_index; i++) {
        objects[i].x--;

        if (objects[i].x == 0){
            obj_index--;

            objects[i] = objects[obj_index];
        }
    }
}


int main() {

    
    for (;;){
        Sleep(100);
        system("cls");

        generateObject();

        fillMatrix();
        printMatrix();
        moveObjects();

        
    }

    return 0;
}