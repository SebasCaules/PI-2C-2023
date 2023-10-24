#include <stdio.h>

int main(void){
    int n, f1, f2, f3;
    for(n=1; n<=20; n++){
        f1 = n*10;
        f2 = n*100;
        f3 = n*1000;
        printf("%d || %d || %d || %d\n",n, f1, f2, f3);
    }
}