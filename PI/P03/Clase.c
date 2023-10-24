#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int main(void){
    int c;
    while ( (c=getchar()) != '\n' ){
        if (!isspace(c)){
            putchar(toupper(c));
        }
    }
}