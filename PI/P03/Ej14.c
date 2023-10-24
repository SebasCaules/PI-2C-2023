#include <stdio.h>

int main(void){
    int c;
    int mayus = 0, minus = 0, espacios = 0;
    while ( (c=getchar()) != '\n' ){
        if (c == 32){
            espacios += 1;
        } else if(c>=65 && c<=90) {
            mayus += 1;
        } else if (c>= 97 && c<=122){
            minus += 1;
        } else {
            break;
        }
    }

}