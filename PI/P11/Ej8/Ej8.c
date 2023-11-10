#include "Ej8.h"
#include <stdlib.h>

typedef struct node {
    elemType head;
    struct node *tail;
} node;

typedef struct node *TList;

typedef struct setCDT{
    TList first;
    int dim;
    compare cmp;
}setCDT;

setADT newSet(compare cmp){
    setADT aux = calloc(1, sizeof(setCDT));
    aux->first = NULL;
    aux->dim = 0;
    aux->cmp = cmp;
    return aux;
}

static void freeListRec(TList list) {
    if (list == NULL) {
        return;
    }
    // Recursion de pila
    freeListRec(list->tail);
    free(list);
}

void freeSet(setADT set){
    freeListRec(set->first);
    free(set);
}

int isEmptySet(setADT set){
    return set->dim == 0;
}

int setContains(const setADT set, elemType element){
    TList aux = set->first;
    while (aux != NULL){
        if(set->cmp(element, aux->head) == 0)
            return 1;
        aux = aux->tail;
    }
    return 0;
}

int addElement(setADT set, elemType element){
    if(setContains(set, element))
        return 0;
    TList aux = malloc(sizeof(setCDT));
    aux->head = element;
    aux->tail = set->first;
    set->first = aux;
    set->dim += 1;
    return 1;
}

static TList deleteElementRec(TList list, elemType elem, compare cmp, int *flag){
    if(list == NULL || list->tail == NULL)
        return list;
    int c = cmp(elem, list->head);
    if(c == 0){
        TList aux = list->tail;
        free(list);
        list = aux;
        *flag = 1;
        return aux;
    }
    return deleteElementRec(list->tail, elem, cmp, flag);
}

int deleteElement(setADT set, elemType element){
    TList aux = set->first;
    while (!(aux == NULL || aux->tail == 0)){
        if((set->cmp(element, aux->tail->head)) == 0){
            TList tailAux = aux->tail->tail;
            free(aux->tail);
            aux->tail = tailAux;
            set->dim -= 1;
            return 1;
        }
        aux = aux->tail;
    }
    return 0;
}

int sizeSet(const setADT set){

}

setADT unionSet(setADT set1, setADT set2){

}

setADT intersectionSet(setADT set1, setADT set2){

}

setADT diffSet(setADT set1, setADT set2){

}
