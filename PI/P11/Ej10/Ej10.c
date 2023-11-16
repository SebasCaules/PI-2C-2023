#include "Ej10.h"
#include <stdlib.h>
#include <strings.h>

struct node {
    elemType head;
    unsigned int count;
    struct node *tail;
};

typedef struct node *nodeP;


struct bagCDT {
    nodeP first;
    unsigned int dim;
    compare cmp;
};

void freeBag(bagADT bag) {
    free(bag);
}

bagADT newBag(compare cmp) {
    bagADT aux = calloc(1, sizeof(struct bagCDT));
    aux->cmp = cmp;
    return aux;
}

void printBag(bagADT bag) {
    size_t dimAUx = bag->dim;
    while (!dimAUx) {
        nodeP aux = malloc(sizeof(struct node));
        aux = bag->first;
        printf("%s\n", aux->head);
        aux = aux->tail;
        dimAUx--;
    }

}

static unsigned int countRec(nodeP first, compare cmp, elemType elem) {
    int c;
    if (first == NULL || (c = cmp(first->head, elem)) > 0)
        return 0;
    if (c == 0)
        return first->count;
    return countRec(first->tail, cmp, elem);
}

unsigned int count(const bagADT bag, elemType elem) {
    return countRec(bag->first, bag->cmp, elem);
}

static nodeP addRec(nodeP first, elemType elem, int *countElem, compare cmp) {
    int c;
    if (first == NULL || (c = cmp(first->head, elem)) > 0) {
        nodeP aux = malloc(sizeof(struct node));

        aux->tail = first;
        aux->head = elem;
        aux->count = 1;
        *countElem = 1;
        return aux;
    }

    if (c < 0)
        first->tail = addRec(first->tail, elem, countElem, cmp);
    else
        *countElem = ++(first->count);
    return first;
}

unsigned int
add(bagADT bag, elemType element) {
    int countElem;
    bag->first = addRec(bag->first, element, &countElem, bag->cmp);
    if (countElem == 1)    // es el primero
        bag->dim++;
    return countElem;
}

unsigned int size(const bagADT bag) {
    return bag->dim;
}

elemType mostPopular(const bagADT bag) {
    elemType ans;
    if ( bag->dim == 0) {
        fprintf(stderr, "El bag no debe estar vacío\n");
        exit(1);
    }
    else {
        nodeP aux = bag->first;
        int cant = aux->count;
        ans = aux->head;
        aux = aux->tail;
        while ( aux != NULL ) {
            if ( aux->count > cant ) {
                ans = aux->head;
                cant = aux->count;
            }
            aux = aux->tail;
        }
    }
    return ans;
}
