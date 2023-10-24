#include <stdio.h>
#include <stdlib.h>
#include "getnum.h"
#include <ctype.h>

int upperLower(int c) {
    return tolower(c);
}

int lowerUpper(int c) {
    return toupper(c);
}

int next(int c) {
    return c+1;
}

int nextAlpha(int c){
    if (isalpha(c)){
        if(c == 'z'){
            return 'a';
        }
        return c+1;
    }else {
        return 0;
    }
}


int main(void) {
    printf("Ingrese un caracter: ");
    int c = getchar();
    printf("%c\n",upperLower(c));
    printf("%c\n",lowerUpper(c));
    printf("%c\n",next(c));
    printf("%c\n",nextAlpha(c));
}