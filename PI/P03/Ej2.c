#include <stdio.h>

int main(void){
    int c1 = getchar();
    int c2 = getchar();
    int ret;

    if(c1 > c2){
        ret = 1;
    }else if(c1 < c2){
        ret = 2;
    }else {
        ret = 0;
    }
    printf("%c es %s a %c", c1, ret!=0 ? (ret==1 ? "Mayor":"Menor"):"Igual", c2);
}