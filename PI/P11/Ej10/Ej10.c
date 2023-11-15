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
    bagADT aux = malloc(sizeof(struct bagCDT));
    aux->first = NULL;
    aux->dim = 0;
    aux->cmp = cmp;
    return aux;
}

static unsigned int inBagRec(bagADT bag, size_t dim, elemType elem) {
    if (dim == 0)
        return 0;
    if(bag->cmp(bag->first->head, elem))
        return 1 + inBagRec(bag++, dim-1, elem);
}

static unsigned int inBag(bagADT bag, elemType elem) {
    if (!bag->dim)
        return 0;

}

unsigned int add(bagADT bag, elemType elem) {

}

unsigned int count(const bagADT bag, elemType elem) {

}

unsigned int size(const bagADT bag) {

}

elemType mostPopular(bagADT bag) {

}
