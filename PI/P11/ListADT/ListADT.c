#include "listADT.h"
#include <stdlib.h>

// Estructura interna para los nodos de la lista
typedef struct node {
    elemType head;
    struct node *tail;
} node;

typedef struct node *TList;

struct listCDT {
    TList first;
    size_t dim; // cantidad de elementos, para hacer más eficiente la función sizeList
    compare cmp;
    TList current;
};

listADT newList(compare f) {
    listADT l = malloc(sizeof(struct listCDT));
    l->first = NULL;
    l->cmp = f;
    l->dim = 0;
    l->current = NULL;
    return l;
}

static void freeListRec(TList list) {
    if (list == NULL) {
        return;
    }
    // Recursion de pila
    freeListRec(list->tail);
    free(list);
}

static void freeListRecTail(TList list) {
    if (list == NULL) {
        return;
    }
    // Recursion de cola
    TList aux = list->tail;
    free(list);
    freeListRecTail(aux);
}

void freeListADT(listADT list) {
    freeListRec(list->first);
    free(list);
}

// Version iterativa de liberar la lista
void freeListADTIter(listADT list) {
    TList aux = list->first;
    while (aux != NULL) {
        TList subList = aux->tail;
        free(aux);
        aux = subList;
    }
    free(list);
}

int isEmptyList(listADT list) {
    return list->dim == 0;  // list->first == NULL;
}

size_t sizeList(listADT list) {
    return list->dim;
}

static int belongsRec(TList list, elemType elem, compare cmp) {
    int c;
    if (list == NULL || (c = cmp(list->head, elem)) > 0) {
        return 0;
    }
    if (c == 0) {
        return 1;
    }
    return belongsRec(list->tail, elem, cmp);
}

int belongsList(listADT list, elemType elem) {
    return belongsRec(list->first, elem, list->cmp);
}

// trabajamos con la lista interna
// en *flag deja 1 si lo agrega,cero si no lo agrega
static TList addRec(TList list, elemType elem, compare cmp, int *flag) {
    int c;
    if (list == NULL || ((c = cmp(elem, list->head)) < 0)) {
        TList aux = malloc(sizeof(node));
        aux->head = elem;
        aux->tail = list;
        *flag = 1;
        return aux;
    }
    if (c > 0) {
        list->tail = addRec(list->tail, elem, cmp, flag);
    }
    return list;
}

// Por ahora hagamos de cuenta que es void
int addList(listADT list, elemType elem) {
    int flag = 0;
    list->first = addRec(list->first, elem, list->cmp, &flag);
    list->dim += flag;
    return flag;
}

static TList deleteListRec(TList list, elemType elem, compare cmp, size_t *flag) {
    int c;
    if (list == NULL || (c = cmp(elem, list->head)) < 0) {
        return list;
    }
    if (c == 0) {
        TList aux = list->tail;
        free(list);
        *flag = 1;
        return aux;
    }

    if (c > 0) {
        list->tail = deleteListRec(list->tail, elem, cmp, flag);
    }
    return list;
}

int deleteList(listADT list, elemType elem) {
    size_t flag = 0;
    list->first = deleteListRec(list->first, elem, list->cmp, &flag);
    list->dim -= flag;
    return flag;
}

void toBegin(listADT list){
    list->current = list->first;
}

size_t hasNext(listADT list){
    return list->current != NULL;
}

elemType next(listADT list){
    if(!hasNext(list))
        exit(1);
    elemType aux = list->current->head;
    list->current = list->current->tail;
    return aux;
}