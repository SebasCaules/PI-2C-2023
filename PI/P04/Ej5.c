#include <stdio.h>
#define maximo2(x, y, max) (x>y ? (max=x):(max=y))

int main(void){
    int max;
    maximo2(3,2, max);
    printf("%d", max);
}
