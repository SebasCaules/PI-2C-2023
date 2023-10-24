#include <stdio.h>

int main(void){
    char c;
    int decimal;
    int suma = 0;
    while ((c = getchar()) != '\n'){
        if ( c == '.' ){
            decimal = 1;
        }
        if( (decimal == 1) && (c>= 48 && c<= 57)){
            c -= 48;
            suma += c;
        }
    }
    printf("%d", suma);
}
