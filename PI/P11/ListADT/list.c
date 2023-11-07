#include <stdlib.h>
#include <stdio.h>
#include "list.h"

// Biblioteca de lista de enteros ordenados sin repetir
/** Retorna 1 si es vacía, cero si no */
int isEmpty(const List list){
   return list==NULL;
}

int belongs(const List list, int elem) {
   if (list==NULL || list->head > elem)
      return 0;
   if (list->head == elem)
      return 1;
   return belongs(list->tail, elem);
}

size_t size(const List list){
   if (isEmpty(list)) {  // o   if ( list == NULL )
     return 0;
   }
   return 1 + size(list->tail);

}

size_t sizeIter(const struct node * list) {
    size_t cant = 0;
    while ( list != NULL ) {
        cant++;
        list = list->tail;
    }
    return cant;
}

List  add(List list, int elem) {
    // Vacia ?   Igual al hesder,   Menor que el header,   Mayor que el header
    if(list==NULL || elem < list->head) {    // o    if ( isEmpty(list))
        List aux = malloc(sizeof(struct node));  //   struct node * aux
        aux->head = elem;
        aux->tail = list;
        return aux;
    }
    // Ya sabemos que list NO es NULL, y elem es mayor o igual al primero
    if ( elem > list->head) {
        // elem es mayor que el primero, hay que insertarlo en la sublista
        list->tail = add(list->tail, elem);
    }
    return  list ;
}

// Version iterativa del add. Si bien al programador que no tenga experiencia con algortimos recursivos
// le pueda resultar más sencilla, al ser iterativo tenemos que contemplar el caso especial de insertar
// al principio.
// Una alternativa para no tener que repetir el código de la creación del nodo es recorrer con dos punteros (el
// anterior y el actual). Y luego de encontrar dónde insertar preguntar si es el caso especial de insertar al
// principio)
List  addIter(List list, int elem) {
    // Caso espeical: es vacia o menor que el primero
    if(list==NULL || elem < list->head) {
        List aux = malloc(sizeof(struct node));
        aux->head = elem;
        aux->tail = list;
        return aux;
    }
    if ( list->head == elem) {
        return list;
    }
    // Al ser iterativo necesitamos tener el puntero al nodo anterior del cual quiero insertar
    struct node * prev = list;
    while ( prev->tail != NULL && prev->tail->head < elem) {
        prev = prev->tail;
    }
    // O bien prev es el último nodo, o el siguiente a prev es mayor o igual que elem, si es igual
    // no hay que insertarlo
    if ( prev->tail == NULL || prev->tail->head > elem ) {
        List aux = malloc(sizeof(struct node));
        aux->head = elem;
        aux->tail = prev->tail;
        prev->tail = aux;
    }
    return  list ;
}


List delete(List list, int elem) {
    if (isEmpty(list) || elem < list->head) {
        return list;
    }
    if (list->head == elem) {
        List aux = list->tail;
        free(list);
        return aux;
    }
    // El elemento puede estar en la sublista
    list->tail = delete(list->tail, elem);
    return list;
}

void freeList(List list){
    if ( list==NULL) {
        return;
    }
    // Mi lista no esta vacia, tengo que eliminar la sublista y liberar el primer nodo
    freeList(list->tail);
    free(list);
}


int head(List list) {
    if ( list == NULL) {
        fprintf(stderr, "head: list can´t be NULL");
        exit(1);
    }
    return list->head;
}

List tail(List list) {
    if ( list == NULL) {
        fprintf(stderr, "tail: list can´t be NULL");
        exit(1);
    }
    return list->tail;
}

int get(List list, size_t idx) {
    if ( list==NULL) {
        fprintf(stderr, "get: invalid indexL");
        exit(1);
    }
    if ( idx == 0) {
        return head(list);
    }
    return get(tail(list), idx-1);
}
