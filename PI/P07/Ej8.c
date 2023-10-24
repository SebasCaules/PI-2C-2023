#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "random.h"
#include "getnum.h"

#define MAX_BOLILLA 90
#define COLS 5
#define FILS 3

typedef int TipoLinea[COLS];
typedef TipoLinea TipoCarton[FILS];

void mezclaArr(int v[], int dim);

void llenaArr(int arr[]);

void generaCarton(TipoCarton carton);

int sacarBolilla(int bolillero[], int *cantBolillas);

int controlarCarton(TipoCarton carton, int bolilla);

void imprimeCarton(TipoCarton carton);

int buscarBolilla(TipoCarton carton, int bolilla);

int controlarLineas(TipoLinea linea);

int jugar(int bolillero[], TipoCarton jugador1, TipoCarton jugador2);


int main(void) {
    int bolillero[MAX_BOLILLA];
    TipoCarton jugador1;
    TipoCarton jugador2;
    int ganador = jugar(bolillero, jugador1, jugador2);
printf("El Ganador es el jugador N° %d\n", ganador);
}

void mezclaArr(int v[], int dim) {
    for (int i = 0; i < dim; i++) {    // shuffle array
        int temp = v[i];
        int randomIndex = randInt(1, dim - 1);
        v[i] = v[randomIndex];
        v[randomIndex] = temp;
    }
}

void llenaArr(int arr[]) {
    for (int i = 0; i < MAX_BOLILLA; ++i) {
        arr[i] = i + 1;
    }
}

void generaCarton(TipoCarton carton) {
    //Genero un vec aux con los numero del 1 al 90
    int vAux[MAX_BOLILLA];
    llenaArr(vAux);
    mezclaArr(vAux, MAX_BOLILLA);

    for (int i = 0, k = 0; i < FILS; ++i) {
        for (int j = 0; j < COLS; ++j, ++k) {
            carton[i][j] = vAux[k];
        }
    }

}

int sacarBolilla(int bolillero[], int *cantBolillas) {
    int ret = bolillero[MAX_BOLILLA - (*cantBolillas)];
    *cantBolillas = (*cantBolillas - 1);
    return ret;
}

int buscarBolilla(TipoCarton carton, int bolilla) {
    for (int i = 0; i < FILS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (carton[i][j] == bolilla) {
                carton[i][j] = 0;
                return 1;
            }
        }
    }
    return 0;
}

int controlarLineas(TipoLinea linea) {
    for (int i = 0; i < COLS; ++i) {
        if (linea[i] != 0)
            return 0;
    }
    return 1;
}

int controlarCarton(TipoCarton carton, int bolilla) {
    buscarBolilla(carton, bolilla);
    int cont = 0;
    for (int i = 0; i < FILS; ++i) {
        cont += controlarLineas(carton[i]);
    }
    return cont;
}

void imprimeCarton(TipoCarton carton) {
    for (int i = 0; i < FILS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%d ", carton[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int jugar(int bolillero[], TipoCarton jugador1, TipoCarton jugador2) {
    srand(time(NULL));
    llenaArr(bolillero);
    mezclaArr(bolillero, MAX_BOLILLA);
    generaCarton(jugador1);
    generaCarton(jugador2);
    int bolilla, cont1 = 0, cont2 = 0, cant = 90, cont = 0;
    int *cantidadBolillas = &cant;
    do {
        bolilla = sacarBolilla(bolillero, cantidadBolillas);
        cont1 += controlarCarton(jugador1, bolilla);
        cont2 += controlarCarton(jugador2, bolilla);
        printf("RONDA N° %d, BOLILLA: %d\n", cont++, bolilla);
        printf("Carton Jugador 1: \n");
        imprimeCarton(jugador1);
        printf("Carton Jugador 2: \n");
        imprimeCarton(jugador2);
    } while (*cantidadBolillas > 0 && (cont1 != 1 && cont2 != 1));
    if (cont1 == 1 && cont2 == 1)
        return 2;
    return 1;
}
