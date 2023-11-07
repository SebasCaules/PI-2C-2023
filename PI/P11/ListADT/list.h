
#ifndef __LIST__H
#define __LIST__H

// Biblioteca de lista de enteros ordenados sin repetir

#include <stdlib.h>

struct node {
   int head;
   struct node * tail;
};

typedef struct node * List;  // list es un alias a puntero a nodo

/** Retorna 1 si es vacía, cero si no */
int isEmpty(const List list);  // o   int isEmpty(const struct node * list);

int belongs(const List list, int elem);

size_t size(const List list);

List  add(List list, int elem);

List delete(List list, int elem);

void freeList(List list);

// Nos devuelve el primer elemento.
// Aborta si la lista esta vacia
int head(List list);

// Nos devuelve la sublista
// Aborta si la lista esta vacia
List tail(List list);

// Retorna el elemento que está en la posición idx,
// el primer elemento está en la posición cero
// (le damos funcionalidad de vector, pero no eficiente)
int get(List list, size_t idx);


#endif
