#include "Ej11.h"
#include <stdlib.h>

#define BLOQUE 10

typedef struct vectorCDT {
    elemType *elems;
    char *isEmpty;    // isEmpty[i] == 1 si elems[i] esta libre, 0 si no está libre
    size_t dim;
    size_t used_spaces;

    int (*compare)(elemType source, elemType target);   // Función de comparación
} vectorCDT;


/* Crea un nuevo vector dinámico de elementos genéricos
** Inicialmente el vector está vacío
** Cada elemento a insertar será de tipo elemType
** Si no se pudo crear retorna NULL.
** La función compare retorna negativo si source es "menor" que target,
** positivo si source es "mayor""que target o cero si se los considera iguales
** (la misma convención que strcmp)
*/
vectorADT newVector(int (*compare)(elemType source, elemType target)) {
    vectorADT aux = calloc(1, sizeof(vectorCDT));
    aux->compare = compare;
    return aux;
}

/* Libera todos los recursos reservados por el TAD */
void freeVector(vectorADT v) {
    if (v != NULL) {
        free(v->elems);
        free(v->isEmpty);
    }
    free(v);
}

/* Almacena los elementos de elems a partir de la posición index, donde elems es
un vector de dim elementos.
** En caso de ser necesario agranda el vector.
** El resto de los elementos del vector no se modifican y permanecen en la misma
posición.
** Si se recibe NULL o no se pudo insertar retorna cero.
** Si alguna posición está ocupada, la deja como estaba.
** Retorna cuántos elementos pudo almacenar.
** Ejemplo:
** si v tiene ocupadas las posiciones 1,3 y 6
** se invoca con index=2, dim=5
** el vector actual quedará con los mismos elementos en las posiciones 1, 3 y 6
** pero además v[2]=elems[0], v[4]=elems[2], v[5]=elems[3]
** y la función retorna 3
*/
size_t put(vectorADT v, elemType *elems, size_t dim, size_t index) {
    if (elems == NULL)
        return 0;
    if (dim + index > v->dim) {
        v->elems = realloc(v->elems, sizeof(elemType) * (dim + index));
        v->isEmpty = realloc(v->isEmpty, sizeof(char) * (dim + index));

        for (size_t i = v->dim; i < dim + index; i++)
            v->isEmpty[i] = 1;
        v->dim = dim + index;
    }
    size_t cont = 0;
    for (size_t i = index, j = 0; i < dim+index; ++i, ++j) {
        if (v->isEmpty[i]) {
            v->elems[i] = elems[j];
            v->isEmpty[i] = 0;
            cont++;
            v->used_spaces++;
        }
    }
    return cont;
}

/* Retorna el índice en el cual está insertado el elemento, o -1 si no lo
encuentra */
int getIdx(vectorADT v, elemType elem) {
    for (int i = 0; i < v->dim; ++i) {
        if(!v->compare(v->elems[i], elem) && v->isEmpty[i] != 1)
            return i;
    }
    return -1;
}

/* Elimina el elemento en la posición index. Si index está fuera del vector no
hace nada */
void deleteElement(vectorADT v, size_t index) {
    if(index > v->dim)
        return;
    if(v->isEmpty[index] != 1){
        v->isEmpty[index] = 1;
        v->used_spaces -=1;
    }
}

/* Retorna cuántos elementos hay insertados en el vector */
int elementCount(vectorADT v) {
    return v->used_spaces;
}
