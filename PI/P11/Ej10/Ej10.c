#include "Ej10.h"
#include <stdlib.h>
#include <strings.h>

struct node {
    elemType head;
    unsigned int count;
    struct node * tail;
};

typedef struct node * nodeP;


struct bagCDT {
    nodeP first;
    unsigned int dim;
    compare cmp;
};

void freeBag(bagADT bag) {
    free(bag);
}

bagADT newBag(compare cmp) {
    bagADT aux = calloc(1,sizeof(struct bagCDT));
    aux->cmp = cmp;
    return aux;
}

void printBag(bagADT bag){
    printf("%s", bag->first->head);
}

static unsigned int countRec(nodeP first,compare cmp, elemType elem){
    int c;
    if(first == NULL || (c=cmp(first->head, elem)) > 0)
        return 0;
    if(c == 0)
        return first->count;
    return countRec(first->tail, cmp, elem);
}

unsigned int count(const bagADT bag, elemType elem){
    return countRec(bag->first, bag->cmp, elem);
}

static nodeP addRec(nodeP first, compare cmp, elemType elem, int * countElem){
    int c;
    if(first == NULL || (c=cmp(first->head, elem)) > 0){
        nodeP aux = malloc(sizeof(struct node));
        aux->tail = first;
        aux->head = elem;
        aux->count = 1;
        *countElem = 1;
        return aux;
    }
    if(c<0)

}

unsigned int add(bagADT bag, elemType elem) {
    if(!bag->dim)
        return 0;
    if(!count(bag, elem))
        bag->first->head =

}

unsigned int count(const bagADT bag, elemType elem) {

}

unsigned int size(const bagADT bag) {

}

elemType mostPopular(bagADT bag) {

}
