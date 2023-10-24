#include <stdio.h>
#define maximo3(x, y, z, max) if(x>y){if(x>z){max=x;} else{max=z;}}else if(y>z){max=y;}else{max=z;}

int main(void){
    int max;
    maximo3(3,666,43131, max);
    printf("%d", max);
}
