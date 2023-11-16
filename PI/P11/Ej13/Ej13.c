#include "Ej13.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct rankingCDT {
    elemType *elems;
    size_t *searches;
    size_t dim;
    compare cmp;
} rankingCDT;

/* Crea un nuevo ranking. Recibe un vector con elementos, donde el primer
** elemento (elems[0]) está al tope del ranking (puesto 1), elems[1] en el
** puesto 2, etc. Si dim es cero significa que no hay elementos iniciales
*/
rankingADT newRanking(elemType elems[], size_t dim, compare cmp) {
    rankingADT aux = calloc(1, sizeof(rankingCDT));
    aux->elems = elems;
    aux->dim = dim;
    aux->cmp = cmp;
    aux->searches = NULL;
    return aux;
}

elemType current(rankingADT ranking, int pos) {
    return ranking->elems[pos];
}

size_t searches(rankingADT ranking, int pos) {
    return ranking->searches[pos];
}

void printRanking(rankingADT ranking){
    for (int i = 0; i < size(ranking); ++i) {
        printf("%zu searches: %s\n", ranking->searches[i], ranking->elems[i]);
    }
    printf("\n");
}


/* Agrega un elemento en la posición más baja del ranking, si no estaba.
** Si el elemento estaba, es equivalente a accederlo, por lo que sube un
** puesto en el ranking
*/

static int belongs(rankingADT ranking, elemType elem) {
    for (int i = 0; i < ranking->dim; ++i) {
        if (!ranking->cmp(ranking->elems[i], elem))
            return i;
    }
    return 0;
}

//Swapeamos los elementos del array entre la posicion del elemento recientemente visitado y
// la del elemento justo arriba en el ranking de este
static void swap(rankingADT ranking, int downgrade, int upgrade) {
    if (downgrade < 0){
        ranking->searches[upgrade]++;
        return;
    } else if((ranking->searches[upgrade] + 1) < ranking->searches[downgrade]){
        ranking->searches[upgrade]++;
        return;
    }
    elemType auxE = ranking->elems[downgrade];
    size_t auxS = ranking->searches[downgrade];
    ranking->elems[downgrade] = ranking->elems[upgrade];
    ranking->searches[downgrade] = ranking->searches[upgrade] + 1;
    ranking->elems[upgrade] = auxE;
    ranking->searches[upgrade] = auxS;
}

void addRanking(rankingADT ranking, elemType elem) {
    int flag = belongs(ranking, elem);
    if (!flag) {
        ranking->dim++;
        ranking->elems = realloc(ranking->elems, (ranking->dim) * sizeof(elemType));
        ranking->searches = realloc(ranking->searches, (ranking->dim) * sizeof(elemType));
        ranking->elems[ranking->dim - 1] = elem;
        ranking->searches[ranking->dim - 1] = 1;
        return;
    }
//    aqui el valor de flag es el valor de la pos del elemento visitado entonces flag-1 es el elemento justo arriba de este
//    en el ranking osea -1 en la posicion del vec
    swap(ranking, flag - 1, flag);
}

/* La cantidad de elementos en el ranking */
size_t size(const rankingADT ranking) {
    return ranking->dim;
}

/* Si n es una posición válida del ranking, guarda en elem el elemento que está
** en el puesto n y retorna 1.
** Si no hay elemento en la posición n, retorna cero y no modifica *elem
** Este acceso también hace que el elemento suba un puesto en el ranking
*/
int getByRanking(rankingADT ranking, size_t n, elemType *elem) {
    if (n > 0 && n < ranking->dim) {
        swap(ranking, n - 2, n - 1);
        *elem = ranking->elems[n - 1];
        return 1;
    }
    return 0;
}

/* top: entrada/salida
** Recibe cuántos elementos al tope del ranking se desean
** Almacena cuántos pudo guardar (ver ejemplos)
** Si el ranking está vacío *top queda en cero y retorna NULL
*/
elemType *getTopRanking(const rankingADT ranking, size_t *top) {
    if(ranking->elems == NULL){
        *top = 0;
        return NULL;
    }
    if(*top >= ranking->dim)
        *top -= ranking->dim;
    elemType * aux = malloc((*top) * sizeof(elemType));
    for (int i = 0; i < *top; ++i) {
        aux[i] = ranking->elems[i];
    }
    return aux;
}

/* 1 si el elemento consultado está en el ranking, cero si no
** Este acceso también hace que el elemento suba un puesto en el ranking
*/
int contains(rankingADT ranking, elemType elem) {
    if (!belongs(ranking, elem))
        return 0;
    return 1;
}

/* Baja una posición en el ranking para el elemento que está en la posición n */
void downByRanking(rankingADT ranking, size_t n) {
    swap(ranking, n, n+1);
}

void freeRanking(rankingADT r) {
    if (r != NULL){
        free(r->elems);
        free(r->searches);
    }
    free(r);
}
