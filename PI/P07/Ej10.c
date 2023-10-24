#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include "random.h"
#include "getnum.h"

#define CANT_PALABRAS 10
#define BLOQUE 5
#define BORRA_BUFFER while (getchar() != '\n')

char *eligePalabra(char *palabras[CANT_PALABRAS]);

char pideLetra(void);

int checkLetra(int letra, char *palabra, char *arrRes);

char *llenaArr(char *palabra);

int checkPalabra(char *arrRes);

void imprimeArr(char *arrRes);

int main(void) {
    srand(time(NULL));
    char *palabras[CANT_PALABRAS] = {
            "AHORCADO",
            "GUAPO",
            "SEBAS",
            "CAPITALES",
            "ARGENTINA",
            "MUNDO",
            "FRANCIA",
            "TETERA",
            "JULIO",
            "SABADO"
    };
    char *palabra = eligePalabra(palabras);
    char *arrRes = llenaArr(palabra);
    int letra;
    int nivel = 0;
    do {
        fflush(stdin);
        printf("Le quedan %d Intentos.\n", 5 - nivel);
        letra = pideLetra();
        nivel += checkLetra(letra, palabra, arrRes);
        imprimeArr(arrRes);
    } while (!checkPalabra(arrRes) && nivel < 5);

    if (nivel == 5) {
        printf("Buena suerte la Proxima, la palbra era: %s\n", palabra);
    } else {
        printf("Felicitaciones, la palabra era: %s\n", palabra);
    }

    free(arrRes);
}

void imprimeArr(char *arrRes) {
    int i = 0;
    while (arrRes[i] != '\0') {
        printf("%c ", arrRes[i]);
        i++;
    }
    printf("\n");
}

char *eligePalabra(char *palabras[CANT_PALABRAS]) {
    int ran = randInt(0, CANT_PALABRAS - 1);
    return palabras[ran];
}

char pideLetra(void) {
    char letra;
    do {
        printf("Ingrese una letra: ");
        letra = toupper(getchar());
        if (letra != '\n')
            BORRA_BUFFER;
    } while (!isupper(letra));
    return letra;
}

char *llenaArr(char *palabra) {
    char *arr = NULL;
    int i = 0;
    while (palabra[i] != '\0') {
        if (i % BLOQUE == 0)
            arr = realloc(arr, (i + BLOQUE) * sizeof(int));
        arr[i] = 95;
        i++;
    }
    arr[i] = 0;
    realloc(arr, (i + BLOQUE) * sizeof(int));
    //return arr; ME DA ERROR Y NO SE PORQUE
}

int checkLetra(int letra, char *palabra, char *arrRes) {
    int i = 0;
    while (palabra[i] != '\0') {
        if (letra == palabra[i] && arrRes[i] == 95) {
            arrRes[i] = letra;
            return 0;
        }
        i++;
    }
    return 1;
}

int checkPalabra(char *arrRes) {
    int i = 0;
    while (arrRes[i] != '\0') {
        if (arrRes[i] == 95)
            return 0;
        i++;
    }
    return 1;
}

