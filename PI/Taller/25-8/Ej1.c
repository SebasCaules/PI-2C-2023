#include <stdio.h>
#include <math.h>

int esPrimo(int x){
    int i;
    if (x==1 || x==0)
        return 0;
    for (i=2; i<= sqrt(x); i++) {
        if ((x % i) == 0) {
            return 0;
        }
    }
    return 1;
}

void mostrarPrimos(int n){
    int j, count;
    for (j=2, count=0; count<=n; j++){
        if (esPrimo(j)){
            printf("%d ", j);
            count++;
        }
    }
}


int main(){
    int b;
    b = esPrimo(7);
    printf("%s es primo \n", b==0 ? "no":"");
    mostrarPrimos(7);
}