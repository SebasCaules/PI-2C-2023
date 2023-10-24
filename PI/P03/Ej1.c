#include <stdio.h>

int main(void){

    printf("Ingrese un caracter: ");
    char c = getchar();
    int ret;
    if(c>64 && c<91){
        ret = 1;
    }else if(c>96 && c<123){
        ret = 2;
    }else {
        ret = 0;
    }

    printf("%c %ss letra %s", c, ret!=0 ? "E":"No e", ret!=0 ? (ret==1 ? "Mayuscula":"Minuscula"):"");

}