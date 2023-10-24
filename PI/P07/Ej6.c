#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "random.h"
#include "getnum.h"

#define X 3
#define MAX_NIVEL 10

void generaAleatorio(int incognita[]);

int elegirNivel(void);

void leerNumero(int numero[]);

int coincideNumero(int incognita[], int numero[]);

int cantidadBien(const int incognita[], const int numero[]);

int cantidadRegular(const int incognita[], const int numero[]);

void mezclaArr(int v[], int dim);

int main(void) {

    int incognita[X];
    generaAleatorio(incognita);
    int nivel = 1;
            //elegirNivel();
    printf("\n");
    int numero[X];
    int coinciden;
    do {
        leerNumero(numero);
        nivel--;
        coinciden = coincideNumero(incognita, numero);
    }while(!coinciden && nivel> 0);

    if(coinciden){
        printf("Muy Bien Ganaste !!!");
    }else{
        printf("Buena suerte la proxima, el numero incognita era: ");
        for (int i = 0; i < X; ++i) {
            printf("%d", incognita[i]);
        }
    }
}

void mezclaArr(int v[], int dim) {
    srand(time(NULL));
    for (int i = 0; i < dim; i++) {    // shuffle array
        int temp = v[i];
        int randomIndex = randInt(1, dim-1);
        v[i] = v[randomIndex];
        v[randomIndex] = temp;
    }
}

void generaAleatorio(int incognita[]) {
    //Llena un array aux con los numero 123456789
    int vAux[] = {1,2,3,4,5,6,7,8,9};
    mezclaArr(vAux, 9);
    for (int i = 0; i < X; ++i) {
        incognita[i] = vAux[i];
    }

}

int elegirNivel(void) {
    int n;
    do {
        n = getint("Ingrese un numero entre el 1 y el %d: ", MAX_NIVEL);
    } while (!(n>0 && n<=MAX_NIVEL));
    return n;
}

void leerNumero(int numero[]) {
    fflush(stdin); //Limpia el buffer de entrada estandar para no agarrar cualquier cosaX
    int i, j, num, numOK;

    do {
        num = getint("Ingrese un numero de %d dígitos del 1 al 9 sin repetir:", X);
        for (i = X - 1, numOK = 1; i >= 0 && numOK; i--, num /= 10) {
            numero[i] = num % 10;
            if (numero[i] == 0)
                numOK = 0;
            else
                for (j = X - 1; j > i && numOK; j--)
                    if (numero[i] == numero[j])
                        numOK = 0;
        }
    } while (!numOK || num != 0);
    /*Si num!=0 entonces el número tenía dígitos de más */
}

int coincideNumero(int incognita[], int numero[]) {
    int cantB = cantidadBien(incognita, numero);
    int cantR = cantidadRegular(incognita, numero);
    printf("%d BIEN, %d REGULAR\n", cantB, cantR);

    for (int i = 0; i < X; ++i) {
        if (incognita[i] != numero[i])
            return 0;
    }
    return 1;
}

int cantidadBien(const int incognita[], const int numero[]) {
    int cont = 0;
    for (int i = 0; i < X; ++i) {
        if (numero[i] == incognita[i])
            cont++;
    }
    return cont;
}

int cantidadRegular(const int incognita[], const int numero[]) {
    int cont = 0;
    int *vecAux = calloc(X, sizeof(int));
    for (int i = 0; i < X; ++i) {
        for (int j = 0; j < X; ++j) {
            if (numero[i] == incognita[j] && j != i && vecAux[j] != 1) {
                cont++;
                vecAux[j] = 1;
            }

        }
    }
    free(vecAux);
    return cont;
}

