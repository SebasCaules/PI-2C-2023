#include <stdio.h>

#define ELAPSED(h1, m1, h2, m2) (((h2)*60)+m2)>(((h1)*60)+m1) ? ((((h2)*60)+m2)-(((h1)*60)+m1)):((((h1)*60)+m1)-(((h2)*60)+m2))

int main(void){
    int minutos1, minutos2, minutos3, h1, h2, m1, m2;
    h1 = 2; m1 = 10; h2 = 3; m2 = 15;
    minutos1 = ELAPSED(h1, m1, h2, m2);
    minutos2 = ELAPSED(3, 15, 2, 10);
    minutos3 = ELAPSED(h1, m1, h1 + 1, m1);
    printf("%d min1 %d min2 %d min3", minutos1, minutos2, minutos3);

}