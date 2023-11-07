#include "Ej10.h"
#include <stdlib.h>
#include <strings.h>

typedef struct bagCDT{
    elemType e;
    size_t dim;
}bagCDT;


void freeBag(bagADT bag){
    free(bag);
}

bagADT newBag(){
    bagADT aux;
    aux->dim = 0;
    return aux;
}

unsigned int add(bagADT bag, elemType elem){
    unsigned int cont = 0;
    while (bag->dim){
        if(compare(bag->e, elem))
            cont++;
        bag++;
    }
    bag->e = elem;
    return cont;
}

unsigned int count(const bagADT bag, elemType elem){

}

unsigned int size(const bagADT bag){

}

elemType mostPopular(bagADT bag){

}
