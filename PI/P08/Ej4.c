#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "random.h"

#define CARTAS 52
#define CARTAS_ENTREGADAS 5
#define MAX_NOMBRE 15

typedef struct {
    int valor;
    char *palo;
} carta;

typedef struct {
    carta carta;
} mazo[CARTAS];


void generaArr(int arr[]);

void mezclaArr(mazo arr);

void llenaMazo(mazo mazo, int numeros[], char *palos[]);

carta *sacaCartas(mazo mazo);

int juega(carta *cartasSacadas);

int main(void) {
    srand(time(NULL));
    int numeros[CARTAS];
    char *palos[] = {"♠", "♣", "♥", "♦"};
    generaArr(numeros);

    mazo mazo;
    llenaMazo(mazo, numeros, palos);
    mezclaArr(mazo);

    carta *cartasS = sacaCartas(mazo);
    for (int i = 0; i < CARTAS_ENTREGADAS; ++i) {
        printf("La %dera carta sacada es el %d %s\n", i+1, cartasS[i].valor, cartasS[i].palo);
    }
    printf("\n");

    int cont = juega(cartasS);
    printf("%d\n", cont);
    switch (cont) {
        case 2:
            printf("En mesa hay PAR\n");
            break;
        case 3:
            printf("En mesa hay PIERNA\n");
            break;
        case 4:
            printf("En mesa hay POKER!!\n");
            break;
        default:
            printf("En mesa no hay NADA\n");
            break;
    }


    free(cartasS);
    return 0;
}

carta *sacaCartas(mazo mazo) {
    carta *cartasSacadas = malloc(sizeof(carta) * CARTAS_ENTREGADAS);
    for (int i = 0; i < CARTAS_ENTREGADAS; ++i) {
        cartasSacadas[i].valor = mazo[i].carta.valor;
        cartasSacadas[i].palo = mazo[i].carta.palo;
    }
    return cartasSacadas;
}

int juega(carta *cartasSacadas){
    int cont = 1;
    for (int i = 0; i < CARTAS_ENTREGADAS; ++i) {
        for (int j = i+1; j < CARTAS_ENTREGADAS; ++j) {
            if(cartasSacadas[i].valor == cartasSacadas[j].valor)
                cont++;
        }
    }
    return cont;
}

void llenaMazo(mazo mazo, int numeros[], char *palos[]) {
    for (int i = 0; i < CARTAS; ++i) {
        mazo[i].carta.valor = (numeros[i] % 13) + 1;
        mazo[i].carta.palo = palos[i / (int) 13];
    }
}

void mezclaArr(mazo arr) {
    for (int i = 0; i < CARTAS; i++) {    // shuffle array
        int tempV = arr[i].carta.valor;
        char *tempP = arr[i].carta.palo;
        int randomIndex = randInt(0, CARTAS - 1);
        arr[i].carta.valor = arr[randomIndex].carta.valor;
        arr[i].carta.palo = arr[randomIndex].carta.palo;
        arr[randomIndex].carta.valor = tempV;
        arr[randomIndex].carta.palo = tempP;

    }
}

void generaArr(int arr[]) {
    for (int i = 0; i < CARTAS; ++i) {
        arr[i] = i;
    }
}

