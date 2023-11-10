#include "diccioADT.h"
#include <stdlib.h>
#include <ctype.h>

typedef struct def{
    char *palabra;
    char *definicion;
    struct def *next;
}definicion;

typedef struct diccioCDT{
    definicion *letra['z'-'a'+1];
}diccioCDT;

static int
strcmpext(const char * a, const char * b) {
    int c = 0;
    while(*a && *b) {
        if((c = (tolower(*a) - tolower(*b))) != 0) {
            return c;
        }
        a++;
        b++;
    }
    return *a - *b;
}

diccioADT creaDiccionario(void){
    return calloc(1, sizeof (diccioCDT));
}

static void liberaRec(diccioADT dic){
    if(dic != NULL)
        if(dic->letra->next != NULL)
            free(dic->letra->next);

}

void liberaDiccionario(diccioADT dic){

}

int agregaPalabra(diccioADT dic, const char * palabra, const char * significado){

}

void imprimeDiccionario(diccioADT dic){

}
