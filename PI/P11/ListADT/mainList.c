#include "listADT.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    // Ejemplo lista de palabras
    // sin repetidos, orden alfabetico
    listADT wordList = newList((int (*)(char *, char *))strcmp);

    assert(isEmptyList(wordList) == 1);
    assert(sizeList(wordList) == 0);

    assert(addList(wordList, "world") == 1);
    assert(addList(wordList, "hello") == 1);
    assert(addList(wordList, "world") == 0);
    assert(addList(wordList, "hola") == 1);

    assert(isEmptyList(wordList) == 0);
    assert(sizeList(wordList) == 3);

    assert(deleteList(wordList, "Hello") == 0);
    assert(deleteList(wordList, "hello") == 1);

    assert(sizeList(wordList) == 2);

    toBegin(wordList);
    while (hasNext(wordList)){
        printf("%s\n", next(wordList));
    }

    freeListADT(wordList);

    puts("OK!");
    return 0;
}
