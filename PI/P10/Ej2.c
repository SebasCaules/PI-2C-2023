#include <stdio.h>
#include "utillist.h"

int main(void){
    int v[] = {1,2,3,4,5,6,7,8,9,10};
    TList myList = fromArray(v, 10);

    int b =get(myList, 3);
    printf("%d\n", b);
    printf("%d\n", (myList->tail)->elem);
    freeList(myList);
}
