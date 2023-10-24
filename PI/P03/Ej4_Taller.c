#include <stdio.h>
#include <math.h>
int esPrimo(int num);

int main(void){
    esPrimo(379);
    esPrimo(503);
    esPrimo(799);
    esPrimo(1001);
    esPrimo(4001);
    esPrimo(111111);


}

int esPrimo(int num) {
    int cont, ret;
    for (cont = 2; cont <= (sqrt(num)); cont++) {
        int comp = num % cont;
        if (comp == 0) {
            ret = 0;
        } else {
            ret = 1;
        }
    }

    printf("%d %s es primo\n", num, ret== 0 ? "No" : "");
    return ret;
}