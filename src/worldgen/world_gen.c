#include "world_gen.h"

int game_matrix[Y][X];
int obj_index = 0, offset = DEFAULT_OFFSET;

Object objects[X];

int randomInt(int min, int max){
    return rand() % max + min;
}

//Debug: prints the matrix
void printMatrix(){
    for (int i = 0; i < Y; i++){
        for (int j = 0; j < X; j++){
            printf("%d", game_matrix[i][j]);
        }
        printf("\n");
    }
}

void fillMatrix(Object *dino) {
    //Fill the matrix with zeros
    //Clear the previous positions
    for (int i = 0; i < Y; i++){
        for (int j = 0; j < X; j++){
            game_matrix[i][j] = 0;
        }
    }

    //Draw the objects onto the matrix
    for (int i = 0; i < obj_index; i++){
        Object curr = objects[i];

        game_matrix[curr.y][curr.x] = (int)curr.type;

        if (curr.type == Cactus && Y - curr.y > 1) {
            for (int j = curr.y; j < Y; j++){
                game_matrix[j][curr.x] = (int)curr.type;
            }
        }
    }

    //Add dino to the matrix overlaying the objects
    for (int i = dino->y; i < Y; i++) {
        if(game_matrix[i][dino->x] == 0){
            game_matrix[i][dino->x] = (int)dino->type;
        }
    }
}

void generateObject() {
    //Avoid objects being to close
    //Offset is controlled by the DEFAULT_OFFSET constant
    if (offset > 0) {
        offset--;
        return;
    }    

    int type_num = randomInt(1, 100);

    //Chances: 80% cactus, 20% bird
    int percent_bird = 20;

    type_num = (float)type_num > percent_bird ? 1 : 2;

    Types type = (Types)type_num;

    int y;
    switch (type) {
        case Cactus:
            y = randomInt(Y-3, Y-1);
            break;

        case Ptero:
            y = randomInt(0, Y-1);
            break;

        default:
            exit(1);
    }
    
    Object obj = {X-1, y, type};

    objects[obj_index++] = obj;        
    offset = DEFAULT_OFFSET;
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


void run(Object *dino) {
    // struct timeb t;
    // ftime(&t);

    int velocity = INITIAL_TICK_SLEEP;

    // int cicle = 15;
    // int jump = 3;
    for (;;){
        //Debug (Doesnt works)
        // if (cicle % 5 == 3 || jump == 3){
        //     dino->y = Y - jump;
        //     jump--;

        //     cicle = 15;
        // }
        //end jump


        srand(time(NULL));
        Sleep(velocity);
        system("cls");

        generateObject();

        fillMatrix(dino);
        printMatrix();

        moveObjects();

        velocity -= velocity > 50 ? 5 : 0;
    }
    
}