#include <stdio.h>
#include <stdlib.h>
#include "random.h"

#define BLOQUE 5

typedef struct {
    int x;
    int y;
} tPunto2D;

typedef tPunto2D *tPos;

int main(void) {
    srand(time(NULL));
    tPunto2D pos;
    tPos tPosiciones = NULL;
    int i = 0;
    pos.x = 0;
    pos.y = 0;
    printf("(%d, %d)\n", pos.x, pos.y);
    do {
        pos.x += randInt(-2, 1);
        pos.y += randInt(-2, 1);
        printf("(%d, %d)\n", pos.x, pos.y);
        if ((i+1) % BLOQUE == 0)
            tPosiciones = realloc(tPosiciones, sizeof(tPunto2D) * ((i+1) + BLOQUE));
        tPosiciones[i++] = pos;
    } while (!(pos.x == 0 && pos.y == 0));
    printf("Chequeo\n");
    for (int j = 0; j < i; ++j) {
        printf("(%d, %d)\n", tPosiciones[j].x, tPosiciones[j].y);
    }

    tPosiciones = realloc(tPosiciones, i);
    free(tPosiciones);
}