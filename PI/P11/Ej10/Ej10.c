#include "Ej10.h"
#include <stdlib.h>
#include <strings.h>

typedef struct bagCDT{
    elemType *e;
}bagCDT;

typedef int (*compare)(elemType e1, elemType e2);

void freeBag( bagADT bag){
    free(bag->e);
    free(bag);
}

bagADT newBag(compare cmp){
    bagADT aux = malloc(sizeof(bagCDT));
    aux->e = cmp;
}

unsigned int add(bagADT bag, elemType elem){

}

unsigned int count(const bagADT bag, elemType elem){

}

unsigned int size(const bagADT bag){

}

elemType mostPopular(bagADT bag){

}

