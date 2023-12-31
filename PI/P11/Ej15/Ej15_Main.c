#include "Ej15.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Para este test completar el .h con:
/*
typedef struct {
    int code;
    char name[20];
} elemType;  	
*/

static int compareStruct(elemType e1, elemType e2) {
    return e1.code - e2.code;
}


int
main(void) {
    printf("Al ejecutar el programa la salida deberia ser:\n"
           "1 uno 2 dos 3 tres 4 cuatro\n"
           "3 tres\n"
           "3 tres 1 uno 2 dos 4 cuatro\n\n");

    moveToFrontADT p = newMoveToFront(compareStruct);

    elemType aux = {1, "uno"};
    assert(add(p, aux) == 1);
    strcpy(aux.name, "dos");
    assert(add(p, aux) == 0);
    aux.code = 2;
    assert(add(p, aux) == 1);
    aux.code = 3;
    strcpy(aux.name, "tres");
    assert(add(p, aux) == 1);
    aux.code = 4;
    strcpy(aux.name, "cuatro");
    assert(add(p, aux) == 1);
    toBegin(p);

    while (hasNext(p)) {
        aux = next(p);
        printf("%d %s ", aux.code, aux.name);
    }
    putchar('\n');

    aux.code = 5;
    elemType *q = get(p, aux);
    assert(q == NULL);

    aux.code = 3;
    q = get(p, aux);
    printf("%d %s\n", q->code, q->name);
    assert(q->code == 3);
    assert(strcmp(q->name, "tres") == 0);
    free(q);

    // Volvemos a pedir el 3, que ahora debe estar al principio
    aux.code = 3;
    q = get(p, aux);
    printf("%d %s\n", q->code, q->name);
    assert(q->code == 3);
    assert(strcmp(q->name, "tres") == 0);
    free(q);

    toBegin(p);
    printf("Debe imprimir 3 tres 1 uno 2 dos 4 cuatro\n");
    int vec[] = {3, 1, 2, 4};
    int i = 0;
    while (hasNext(p)) {
        aux = next(p);
        printf("%d %s ", aux.code, aux.name);
        assert(aux.code == vec[i++]);
    }
    putchar('\n');

    aux.code = 5;
    strcpy(aux.name, "cinco");
    assert(add(p, aux) == 1);
    q = get(p, aux);
    assert(q->code == 5);
    assert(strcmp(q->name, "cinco") == 0);
    free(q);
    toBegin(p);
    assert(next(p).code == 5);
    assert(next(p).code == 3);


    freeMoveToFront(p);
    puts("OK!");
    return 0;
}