#include <stdio.h>
#include <stdlib.h>
#include "utillist.h"

/*
** Funcion auxiliar para crear listas y poder testear las funciones
** Dado un vector, retorna una lista con sus elementos, en el mismo orden
*/

int isEmpty(const TList list) {
    return list == NULL;
}

TList fromArray(const int v[], unsigned int dim) {
    TList ans = NULL;
    while (dim) {
        TList aux = malloc(sizeof(TNode));
        aux->elem = v[--dim];
        aux->tail = ans;
        ans = aux;
    }
    return ans;
}

/*
** Funcion auxiliar para verificar los elementos de una lista
** Retorna 1 si la lista y el vector contienen los mismos elementos en el mismo orden
*/
int checkElems(const TList list, const int v[], int dim) {
    int i;
    TList aux;
    for (i = 0, aux = list; i < dim && aux != NULL; i++, aux = aux->tail) {
        if (aux->elem != v[i])
            return 0;
    }
    return aux == NULL && i == dim;
}

void freeList(TList list) {
    if (list == NULL)
        return;
    freeList(list->tail);
    free(list);
}

TList delete(TList list, int elem) {
    if (isEmpty(list) || elem < list->elem) {
        return list;
    }
    if (list->elem == elem) {
        TList aux = list->tail;
        free(list);
        return aux;
    }
    // El elemento puede estar e9n la sublista
    list->tail = delete(list->tail, elem);
    return list;
}

int get(const TList list, unsigned int i) {
    TNode *current = list;
    unsigned int currentIndex = 0;

    while (current != NULL && currentIndex < i) {
        current = current->tail;
        currentIndex++;
    }
}

TList addInFront(TList list, int element) {
    TNode *newNode = (TNode *) malloc(sizeof(TNode));
    if (newNode == NULL) {
        // Handle memory allocation error
        exit(1);
    }

    newNode->elem = element;
    newNode->tail = list;

    return newNode; // The new node becomes the new head of the list.
}

TList add(TList l, int elem) {
    if (l == NULL || elem < l->elem) {
        TList aux = malloc(sizeof(struct node));
        aux->elem = elem;
        aux->tail = l;
        return aux;
    }
    if (elem == l->elem) {
        return l;
    }
    l->tail = add(l->tail, elem);
    return l;
}

void printList(TList list) {
    while (list != NULL) {
        printf("%d ", list->elem);
        list = list->tail;
    }
    printf("\n");
}