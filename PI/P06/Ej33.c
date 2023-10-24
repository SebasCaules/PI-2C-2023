#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "random.h"
#include <time.h>

#define ALF ('Z' - 'A')
#define MAX 100

void crearAlfabeto(char v[]);

void codificar(char *msj,const char alf[], char *msjCod);

void decodificar(char *msjCod,const char alf[], char *msjDecod);

void randomArray(int v[], int izq, int der);


int main(void) {
    char msg[MAX];
    char dest[MAX];
    // Debemos probar con mayusculas, porque siempre decodifica a mayuscuas
    char *s = "MENSAJE A CODIFICAR";
    char *s2 = "Mensaje a codificar";
    char alpha[MAX];



    crearAlfabeto(alpha);
    printf("\n");

    codificar(s, alpha, msg);
    assert(strlen(s) == strlen(msg));
    assert(strcmp(s, msg) != 0);
    decodificar(msg, alpha, dest);
    assert(strcmp(dest, s) == 0);

    codificar(s2, alpha, msg);
    assert(strlen(s2) == strlen(msg));
    assert(strcmp(s2, msg) != 0);
    decodificar(msg, alpha, dest);
    assert(strcmp(dest, s) == 0);

    puts("OK");
    return 0;
}


void randomArray(int v[], int izq, int der) {
    srand(time(NULL));
    for (int i = izq; i <= der; i++) {     // fill array
        v[i] = i;
    }
    printf("\n");
    for (int i = 0; i <= ALF; ++i) {
        printf("%c ", v[i]+'A');
    }
    for (int i = 0; i < der; i++) {    // shuffle array
        int temp = v[i];
        int randomIndex = randInt(izq, der);
        v[i] = v[randomIndex];
        v[randomIndex] = temp;
    }
}

void crearAlfabeto(char v[]) {
    int vRand[ALF+1];
    randomArray(vRand, 0, 25);
    printf("\n");
    for (int i = 0; i <= ALF; ++i) {
        v[i] = vRand[i] + 'A';
    }

    //Imprime
    for (int i = 0; i <= ALF; ++i) {
        printf("%c ", v[i]);
    }
}

void codificar(char *msj,const char alf[], char *msjCod) {
    int i = 0;
    while (msj[i] != '\0') {
        if (msj[i] != 32) {
            msjCod[i++] = alf[msj[i] - 'A'];
        } else
            msjCod[i++] = 32;
    }
    printf("%s \n", msj);
    printf("%s ", msjCod);

    printf("\n");

    return;

}

int buscaAlf(char letra,const char alf[]){
    for (int i = 0; i <= ALF+1; ++i) {
        if(letra == alf[i])
            return i;
    }
}


void decodificar(char *msjCod,const char alf[], char *msjDecod) {
    char *alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alfabetoCod[ALF+1];
    codificar(alfabeto, alf, alfabetoCod);
    int i = 0;
    while (msjCod[i] != '\0') {
        if (msjCod[i] != 32) {
            msjDecod[i++] = alfabeto[buscaAlf(msjCod[i], alf)];
        } else
            msjDecod[i++] = 32;
    }
    printf("%s \n", msjDecod);
    return;
}
