#ifndef __utillist__h
#define __utillist__h

typedef struct node *TList;

typedef struct node {
    int elem;
    struct node *tail;
} TNode;


/*
** Funcion auxiliar para crear listas y poder testear las funciones
** Dado un vector, retorna una lista con sus elementos, en el mismo orden
*/
TList fromArray(const int v[], unsigned int dim);

/*
** Funcion auxiliar para verificar los elementos de una lista
** Retorna 1 si la lista y el vector contienen los mismos elementos en el mismo orden
*/
int checkElems(const TList list, const int v[], int dim);

/*
** Libera todos los nodos de la lista
*/
void freeList(TList list);

int isEmpty(const TList list);

TList delete(TList list, int elem);

int get(const TList list, unsigned int i);

TList addInFront(TList list, int element);

TList add(TList l, int elem);

void printList(TList list);

#endif