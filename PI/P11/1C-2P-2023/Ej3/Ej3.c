#include "Ej3.h"
#include <stdlib.h>
#include <stdio.h>
typedef struct node {
    elemtype value;
    size_t apCount;
    struct node * next;
} node;

typedef struct node * list;

typedef struct elemCountCDT {
    list first;
    list last;
    size_t dim;
    compare cmp;
} elemCountCDT;

void printEl(elemCountADT elemCountAdt){
    printf("%d\n", elemCountAdt->first);
}


/* Crea todos los recursos para el TAD
** Arranca inicialmente sin elementos.
*/
elemCountADT newElemCount(compare cmp) {
    elemCountADT aux = calloc(1, sizeof(elemCountCDT));
    aux->cmp = cmp;
    return aux;
}

static void freeRec(list l){
    if(l == NULL)
        return;
    freeRec(l->next);
    free(l);
}

/* Libera los recursos utilizados por el TAD */
void freeElemCount(elemCountADT elemCountAdt) {
    if(elemCountAdt != NULL){
        freeRec(elemCountAdt->first);
    }
    free(elemCountAdt);
}

static size_t belongs(list first, size_t dim,compare cmp, elemtype elem){
    if(first == NULL)
        return 0;
    list aux = first;
    for (int i = 0; i < dim && aux != NULL; ++i) {
        if(!cmp(aux->value, elem))
            return 1;
        aux = aux->next;
    }
    return 0;
}

static list addRec(list first, elemtype elem, compare cmp) {
    int c;
    if (first == NULL || (c = cmp(first->value, elem)) > 0) {
        list aux = malloc(sizeof(struct node));
        aux->value = elem;
        aux->next = first;
        aux->apCount = 1;
        return aux;
    }
    if (c < 0)
        first->next = addRec(first->next, elem, cmp);
    return first;
}


static list countElemRec(list first, compare cmp, elemtype elem, size_t *flag){
    if(first == NULL)
        return first;
    if(!cmp(first->value, elem)){
        return first;
    }
    first = countElemRec(first->next, cmp, elem, flag);
    return first;
}

/* Registra una aparición de elem y retorna la cantidad actual de
** apariciones registradas.
*/
size_t countElem(elemCountADT elemCountAdt, elemtype elem) {
    int belongsFlag = belongs(elemCountAdt->first, elemCountAdt->dim, elemCountAdt->cmp, elem);
    if (!belongsFlag){
        addRec(elemCountAdt->first, elem, elemCountAdt->cmp);
        return 1;
    }
    size_t flag = 0;
    list aux = countElemRec(elemCountAdt->first, elemCountAdt->cmp, elem, &flag);
    printf("%d", aux->value);
    aux->apCount += 1;
    return aux->apCount;
}

/* Retorna la cantidad de elementos distintos registrados. */
size_t distinctElems(elemCountADT elemCountAdt) {
    return elemCountAdt->dim;
}

/* Funciones de iteración para que se puedan consultar todos los elementos
** registrados en forma ordenada
** junto con la cantidad de apariciones de cada uno.
*/
void toBegin(elemCountADT elemCountAdt) {
    elemCountAdt->first =
}

size_t hasNext(elemCountADT elemCountAdt) {

}

elemtype next(elemCountADT elemCountAdt, size_t *count) {

}

