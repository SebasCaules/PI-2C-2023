#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int elem;
    struct node * tail;
} TNode;

typedef struct node * TList;

void deleteNonAsc(TList list){
    if(list == NULL || list->tail == NULL)
        return;
    if(list->elem >= list->tail->elem){
        TList aux = list->tail;
        list->tail = list->tail->tail;
        free(aux);
        deleteNonAsc(list);
    }else
        deleteNonAsc(list->tail);
}

TList fromArray(const int v[], unsigned int dim ) {
    TList ans = NULL;
    while (dim) {
        TList aux = malloc(sizeof(TNode));
        aux->elem = v[--dim];
        aux->tail = ans;
        ans = aux;
    }
    return ans;
}

void freeList(TList list) {
    if ( list == NULL)
        return;
    freeList(list->tail);
    free(list);
}

void printList(TList list){
    if(list == NULL)
        return;
    printf("%d\t", list->elem);
    printList(list->tail);
}

int main(void){
    int v[] = {12,2,3,4,6,5, 4, 7, 9};
    TList lista= fromArray(v, 9);
    printList(lista);
    printf("\n");
    deleteNonAsc(lista);
    printList(lista);
    freeList(lista);
}