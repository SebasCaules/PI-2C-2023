#include <glob.h>
#include "Ej3.h"
#include <stdlib.h>

typedef struct node{
    elemType head;
    struct node * next;
}TNode;

typedef struct node * TList;

typedef struct listCDT{
    TList first;
    size_t dim;
    int (*compare)(elemType e1, elemType e2);
    TList currentIns;
    TList currentAsc;
}listCDT;

/* Retorna una lista vacía.*/
listADT newList(int (*compare)(elemType e1, elemType e2)){
    listADT aux = calloc(1, sizeof(struct listCDT));
    aux->compare =compare;
    return aux;
}

static TList addRec(TList first, elemType elem, int (*compare)(elemType e1, elemType e2)){
    int c;
    if(first == NULL || (c = compare(first->head, elem)) > 0){
        TList aux = malloc(sizeof(TNode));
        aux->head = elem;
        aux->next = first;
        return aux;
    }
    if(c<0)
        first->next = addRec(first->next, elem, compare);
    return first;
}

/* Agrega un elemento. Si ya estaba no lo agrega */
void add(listADT list, elemType elem){
    list->first = addRec(list->first, elem, list->compare);
    list->currentIns = list->first;
}

/* Elimina un elemento. */
/*void remove(listADT list, elemType elem){

}*/

/* Resetea el iterador que recorre la lista en el orden de inserción */
void toBegin(listADT list){
    list->currentIns = list->first;
}

/* Retorna 1 si hay un elemento siguiente en el iterador que
** recorre la lista en el orden de inserción. Sino retorna 0 */

int hasNext(listADT list){
    return list->currentIns->next != NULL;
}

/* Retorna el elemento siguiente del iterador que recorre la lista en el orden de inserción.
** Si no hay un elemento siguiente o no se invocó a toBegin aborta la ejecución.
*/
elemType next(listADT list){
    if(list->currentIns == NULL || !hasNext(list))
        exit(1);
    return list->currentIns->head;
}

/* Resetea el iterador que recorre la lista en forma ascendente */
void toBeginAsc(listADT list){
    list->currentAsc = list->first;
}

/* Retorna 1 si hay un elemento siguiente en el iterador que
** recorre la lista en forma ascendente. Sino retorna 0 */

int hasNextAsc(listADT list){
    return list->currentAsc->next != NULL;
}

/* Retorna el elemento siguiente del iterador que recorre la lista en forma ascendente.
** Si no hay un elemento siguiente o no se invocó a toBeginAsc aborta la ejecución.
*/
elemType nextAsc(listADT list){
    if(list->currentAsc == NULL || !hasNextAsc(list))
        exit(1);
    return list->currentAsc->head;
}

static void freeListRec(TList list) {
    if (list == NULL) {
        return;
    }
    // Recursion de pila
    freeListRec(list->next);
    free(list);
}
void freeListADT(listADT list) {
    freeListRec(list->first);
    free(list);
}
