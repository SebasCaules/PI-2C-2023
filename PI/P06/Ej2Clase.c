#include <stdio.h>

int esta(int v[], int num, int dim){
    int esta = 0, *fin = v+dim;
    while (v<fin && !esta){
        if(*v==num){
            esta = 1;
        }
        v++;
    }
    return esta;
}


int main(void){
    int v[] = {1, 2, 3,4,5,6,7,8,9,10,11};
    int *p=v;
    int num = 4;
    int b = esta(p, num, 3);
    printf("%d", b);
}