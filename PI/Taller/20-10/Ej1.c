#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define OK 1
#define NOOK !OK
#define NOTA_APROBADO 6
#define BLOQUE 10

int obtenerAprobados(char *arrNombres[], int tam, char *aprobados[], const int notas[]);

static void mostrarNombres(char *arrNombres[], size_t n);

static void liberarAprobados(char * aprobados[], size_t n);

int
main(void) {
    char *arrNombres[] = {"anita", "pepe", "fabi", "carlos", "tere"};
    char *aprobados[5];
    int notas[] = {3, 4, 8, 10, 1};
    int tam, tamApro;
    tam = sizeof(arrNombres) / sizeof(char *);
    mostrarNombres(arrNombres, tam);
    tamApro = obtenerAprobados(arrNombres, tam, aprobados, notas);
    printf("Aprobados:\n");
    mostrarNombres(aprobados, tamApro);

    // Test del ejemplo
    char *aprobados1[5];
    assert(obtenerAprobados(arrNombres, 0, aprobados1, notas) == 0);
    assert(obtenerAprobados(arrNombres, 1, aprobados1, notas) == 0);
    assert(obtenerAprobados(arrNombres, 2, aprobados1, notas) == 0);
    assert(obtenerAprobados(arrNombres, 3, aprobados1, notas) == 1);
    assert(strcmp(aprobados1[0], "fabi") == 0);
    char *aprobados2[5];
    assert(obtenerAprobados(arrNombres, 4, aprobados2, notas) == 2);
    assert(strcmp(aprobados2[0], "fabi") == 0);
    assert(strcmp(aprobados2[1], "carlos") == 0);
    char *aprobados3[5];
    assert(obtenerAprobados(arrNombres, 5, aprobados3, notas) == 2);
    assert(strcmp(aprobados3[0], "fabi") == 0);
    assert(strcmp(aprobados3[1], "carlos") == 0);

    printf("\nOK!\n");

    free(aprobados1);
    free(aprobados2);
    free(aprobados3);
    return 0;
}


int obtenerAprobados(char *arrNombres[], int tam, char *aprobados[], const int notas[]) {
    int i, j;
    for (i = 0, j = 0; i < tam; ++i) {
        aprobados[i] = malloc(strlen(arrNombres[i]) + 1);
        if(notas[i] >= NOTA_APROBADO){
            strcpy(aprobados[j], arrNombres[i]);
            j++;
        }

    }
    return j;
}

static void mostrarNombres(char *arrNombres[], size_t n){
    for (int i = 0; i < n; ++i) {
        printf("%s\n", arrNombres[i]);
    }
}