#include "Ej3.h"
#include <stdlib.h>

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

static list countElemRec(list first, compare cmp, elemtype elem, size_t *flag, size_t dim){
    int c;
    if(belongs(first, dim, cmp, elem) &&(first == NULL || (c = cmp(first->value, elem)) > 0 )){
        list aux = malloc(sizeof(node));
        aux->value = elem;
        aux->next = first;
        aux->apCount = 1;
        return aux;
    }
    if(c<0)
        first->next = countElemRec(first->next, cmp, elem, flag, dim);
    else
        *flag = ++first->apCount;
    return first;
}

/* Registra una aparición de elem y retorna la cantidad actual de
** apariciones registradas.
*/
size_t countElem(elemCountADT elemCountAdt, elemtype elem) {


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

}

size_t hasNext(elemCountADT elemCountAdt) {

}

elemtype next(elemCountADT elemCountAdt, size_t *count) {

}

