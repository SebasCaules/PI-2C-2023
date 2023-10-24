#include <stdio.h>

int main(void){
    int c;
    while((c= getchar()) != '\n'){
        if(c == 32){
            printf("\n");
        }else {
            printf("%c",c);
        }
    }
}
