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
    return set->dim;
}

setADT
unionSet(setADT set1, setADT set2) {
    // Asumimos que la funcion de comparacion es la misma en ambos conjuntos
    setADT set;
    listADT l1, l2;

    set = newSet(set1->cmp);
    if (set == NULL)
        return NULL;

    l1 = set1->;
    toBegin(l1);

    /* Si set1 y set2 son el mismo conjunto, no podemos iterar como
    ** si fueran dos conjuntos distintos (se mezclarían los iteradores)
    */
    if (set1 == set2) 	{
        while (hasNext(l1))
            addElement(set, next(l1));
        return set;
    }

    /* Podríamos agregar todos los elementos de l1 y luego todos los de l2
    ** pero no sería muy eficiente
    */
    l2 = set2->list;
    toBegin(l2);

    if (hasNext(l1) || hasNext(l2)) {
        elemType e1, e2;

        int has1, has2;

        if ((has1 = hasNext(l1)))
            e1 = next(l1);
        if ((has2 = hasNext(l2)))
            e2 = next(l2);

        while (has1 || has2) 		{
            if (!has2 || (has1 && set1->cmp(e1, e2) < 0)) {
                addElement(set, e1);
                if ((has1 = hasNext(l1)))
                    e1 = next(l1);
            } else if (!has1 || (has2 && set1->cm[(e1, e2) > 0)) {
                addElement(set, e2);
                if ((has2 = hasNext(l2)))
                    e2 = next(l2);
            } else { // son iguales
                addElement(set, e1);
                if ((has1 = hasNext(l1)))
                    e1 = next(l1);
                if ((has2 = hasNext(l2)))
                    e2 = next(l2);
            }
        }
    }
    return set;
}

setADT intersectionSet(setADT set1, setADT set2){

}

setADT diffSet(setADT set1, setADT set2){

}
