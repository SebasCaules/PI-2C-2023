//
// ADT para listas genérica, ordenadas y sin repetidos
//

#ifndef _LISTADT_H
#define _LISTADT_H

#include <stdlib.h>

// El tipo de datos a insertar, definido por el usuario
typedef int elemType;

typedef struct listCDT * listADT;

/**
 * Puntero a función de comparación
 * Retorna 0 si son iguales
 *        <0 si el primero es "menor" que el segundo
 *        >0 si el primero es "mayor" que el segundo
 */
typedef int (* compare) (elemType, elemType);

/**
 *
 * @return una lista vacía
 */
listADT newList(compare cmp);

void freeListADT(listADT list);

int isEmptyList(listADT list);

size_t sizeList(listADT list);

int belongsList(listADT list, elemType elem);

/**
 * Agrega -si no estaba- un elemento a la lista
 * @param list
 * @param elem
 * @return 1 si lo agrega, cero sinó
 */
int addList(listADT list, elemType elem);

int deleteList(listADT list, elemType elem);

#endif
