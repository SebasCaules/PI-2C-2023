#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "random.h"
#include "getnum.h"

#define BLOQUE 5

typedef struct {
    int posX;
    int posY;
} posicion;

posicion caminata(posicion pos);

int recorrido(int radio);

void relacionRat(void);

int main(void) {
    srand(time(NULL));
    relacionRat();

}

posicion caminata(posicion pos) {
    posicion movimientos[] = {
            {1,  0},
            {-1, 0},
            {0,  1},
            {0,  -1}
    };

    int rand = randInt(0, 3);
    pos.posX = pos.posX + movimientos[rand].posX;
    pos.posY = pos.posY + movimientos[rand].posY;
    return pos;
}

int recorrido(int radio) {
    if (radio <= 0)
        return 0;
    int t = 0;
    posicion pos = {0, 0};
    while ((pow(pos.posX, 2) + pow(pos.posY, 2)) <= pow(radio, 2)) {
        pos = caminata(pos);
        t++;
    }
    return t;
}

void relacionRat(void) {
    int cantRadios = getint("Ingrese la cantidad de radios a provar: ");
    int radios[cantRadios];
    for (int i = 0; i < cantRadios; ++i) {
        radios[i] = (int) pow(i + 1, 2);
    }
    double *relacion = NULL;
    int *t = NULL;
    int i;
    printf("Radio\tTiempo\tRelacion\n");
    for (i = 0; i < cantRadios; ++i) {
        if (i % BLOQUE == 0) {
            relacion = realloc(relacion, sizeof(double ) * (i + BLOQUE));
            t = realloc(t, sizeof(int) * (i + BLOQUE));
        }
        t[i] = recorrido(radios[i]);
        relacion[i] = radios[i] / (double)t[i];
        printf("%d m\t%d s\t%g m/s\n", radios[i], t[i], relacion[i]);

    }
    t = realloc(t, sizeof(int) * i);
    relacion = realloc(relacion, sizeof(int) * i);

    free(t);
    free(relacion);
}