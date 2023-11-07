#include <assert.h>
#include <stdio.h>
#include "listADT.h"

int cmpInts(int a, int b) {
    return a-b;
}

int
main(void) {
   listADT adt = newList(cmpInts);
    assert(sizeList(adt)==0);
    assert(belongsList(adt, 10)==0);
    assert(isEmptyList(adt));



    assert(addList(adt, 10));
    assert(sizeList(adt)==1);
    assert(belongsList(adt, 10)==1);
    assert(belongsList(adt, 20)==0);
    assert(!isEmptyList(adt));

    myList = add(myList, 5);
    assert(size(myList)==2);
    assert(belongs(myList, 10)==1);
    assert(belongs(myList, 5)==1);

    myList = add(myList, 5);
    myList = add(myList, 10);


    assert(size(myList)==2);
    assert(belongs(myList, 10)==1);
    assert(belongs(myList, 5)==1);

    myList = add(myList, 55);  // al final
    myList = add(myList, 20);  //  en el medio
    assert(size(myList)==4);

    assert(belongs(myList, 10)==1);
    assert(belongs(myList, 5)==1);

    myList = delete(myList, 10);
    assert(size(myList)==3);
    assert(belongs(myList, 10)==0);
    assert(belongs(myList, 5)==1);

    // Quiero imprimir todos los elementos, o sumarlos
    List aux = myList;
    while(! isEmpty(aux)) {
        printf("%d ", head(aux));
        aux = tail(aux);
    }
    putchar('\n');


   int cant = size(myList);
   for(int i=0; i < cant; i++) {
       printf("%d ", get(myList, i));
   }
   putchar('\n');


   freeList(myList);
    freeListADT(adt);
   puts("OK!");
   return 0;
}
