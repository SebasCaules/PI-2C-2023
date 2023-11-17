#include <assert.h>
#include <stdio.h>
#include "Ej3.h"

static int compare (elemType e1, elemType e2) {
    return e1 - e2;
}
int
main(void) {
    listADT c = newList(compare); // una lista, en este caso de int
    add(c, 3);
    add(c, 1);
    add(c, 5);
    add(c, 2);

    toBegin(c); // iterador por orden de inserción
    int n = next(c); // n = 3
    printf("%d", n);
    /*
    assert(n == 3);
    n = next(c);
    assert(n == 1);// n = 1
    toBeginAsc(c); // iterador por orden ascendente
    n = nextAsc(c);
    assert(n == 1);// n = 1
    n = next(c);
    assert(n == 5);// n = 5
    n = next(c);
    assert(n == 2);// n = 2
    assert(hasNextAsc(c) == 0); // retorna 0 ( falso )
    n = nextAsc(c);
    assert(n == 2);// n = 2
    assert(hasNextAsc(c) == 1); // retorna 1 ( true )
    n = nextAsc(c);
    assert(n == 3);// n = 3*/

    freeListADT(c);
    return 0;
}
