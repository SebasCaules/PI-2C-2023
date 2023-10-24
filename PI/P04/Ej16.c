#include <stdio.h>
#define divisor(x, y) (x%y==0 ? 1:0)


int main(void){
    int a, b, c=10, d=2;
    a = divisor(c,d);
    b= divisor(c,d+1);
    printf("%d es a y b es %d", a, b);
}