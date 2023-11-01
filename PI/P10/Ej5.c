#include <stdio.h>
#include <assert.h>
#include "utillist.h"
#include <stdlib.h>

TList restaList(TList lista1, TList lista2);

#define ELEMS 200

int main(void) {

    int pares[ELEMS], impares[ELEMS];

    for (int i = 1; i <= ELEMS; i++) {
        pares[i - 1] = i * 2;
        impares[i - 1] = i * 2 - 1;
    }

    TList lPar = fromArray(pares, ELEMS);
    TList lImpar = fromArray(impares, ELEMS);

    TList lPar2 = restaList(lPar, lImpar);
    assert(checkElems(lPar2, pares, ELEMS));
    printf("Hola");
    // Verificamos ademas que no sean los mismos nodos
    assert(lPar2 != lPar);
    assert(lPar2->tail != lPar->tail);
    freeList(lPar2);
    freeList(lPar);
    freeList(lImpar);

    int all[ELEMS * 2];
    for (int i = 1, j = 0; i <= ELEMS; i++) {
        all[j++] = i * 2 - 1;
        all[j++] = i * 2;
    }
    TList lAll = fromArray(all, ELEMS * 2);
    lPar = fromArray(pares, ELEMS);
    TList lImpar2 = restaList(lAll, lPar);
    assert(checkElems(lImpar2, impares, ELEMS));
    freeList(lPar);

    lPar = restaList(lAll, lImpar2);
    assert(checkElems(lPar, pares, ELEMS));
    freeList(lPar);
    freeList(lAll);

    lPar = NULL;
    lImpar = fromArray(impares, ELEMS);
    TList aux = restaList(lPar, lImpar);
    assert(aux == NULL);
    freeList(lImpar);

    aux = restaList(lImpar2, lImpar2);
    assert(aux == NULL);
    freeList(lImpar2);

    printf("OK!\n");
    return 0;
}

TList restaList(TList lista1, TList lista2) {
    if (lista2 == NULL || lista1 == NULL  || lista1->tail == NULL)
        return lista1;
    if(lista1->elem > lista2->elem)
        return restaList(lista1, lista2->tail);
    if(lista1->elem < lista2->elem){
        TList aux = malloc(sizeof(TNode));
        aux->elem = lista1->elem;
        aux->tail = restaList(lista1->tail, lista2);
        return aux;
    }
    return restaList(lista1, lista2->tail);
}