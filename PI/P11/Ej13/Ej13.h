//
// Created by sebas on 11/15/2023.
//

#ifndef rankingADT_h
#define rankingADT_h

#include <glob.h>

typedef const char * elemType;

typedef struct rankingCDT * rankingADT;

typedef int (*compare)(elemType source, elemType target);


/* Crea un nuevo ranking. Recibe un vector con elementos, donde el primer
** elemento (elems[0]) está al tope del ranking (puesto 1), elems[1] en el
** puesto 2, etc. Si dim es cero significa que no hay elementos iniciales
*/
rankingADT newRanking(elemType elems[], size_t dim, compare cmp);

/* Agrega un elemento en la posición más baja del ranking, si no estaba.
** Si el elemento estaba, es equivalente a accederlo, por lo que sube un
** puesto en el ranking
*/

elemType current(rankingADT ranking, int pos);

size_t searches(rankingADT ranking, int pos);

void printRanking(rankingADT rankingAdt);

void addRanking(rankingADT ranking, elemType elem);

/* La cantidad de elementos en el ranking */
size_t size(const rankingADT ranking);

/* Si n es una posición válida del ranking, guarda en elem el elemento que está
** en el puesto n y retorna 1.
** Si no hay elemento en la posición n, retorna cero y no modifica *elem
** Este acceso también hace que el elemento suba un puesto en el ranking
*/
int getByRanking(rankingADT ranking, size_t n, elemType * elem);

/* top: entrada/salida
** Recibe cuántos elementos al tope del ranking se desean
** Almacena cuántos pudo guardar (ver ejemplos)
** Si el ranking está vacío *top queda en cero y retorna NULL
*/
elemType * getTopRanking(const rankingADT ranking, size_t * top);

/* 1 si el elemento consultado está en el ranking, cero si no
** Este acceso también hace que el elemento suba un puesto en el ranking
*/
int contains(rankingADT ranking, elemType elem);

/* Baja una posición en el ranking para el elemento que está en la posición n */
void downByRanking(rankingADT ranking, size_t n);

void freeRanking(rankingADT r);


#endif //P11_EJ13_H