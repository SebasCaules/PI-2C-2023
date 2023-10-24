#include <stdio.h>
#define DIF 'a'-'A'

int main(void) {

    int a, b, c;
    a = getchar();
    b = getchar();
    c = getchar();


    if ((a>65 && a<69) || (a>69 && a<73) || (a>73 && a<79) || (a>79 && a<85) || (a>85 && a<91)){

    }
        printf("El caracter %c es una consonante mayúscula \n", a);
    else if ((a>65+DIF && a<69+DIF) || (a>69+DIF && a<73+DIF) || (a>73+DIF && a<79+DIF) || (a>79+DIF && a<85+DIF) || (a>85+DIF && a<91+DIF))
        printf("El caracter %c es una consonante minúscula \n", a);
    else if ( a==65 || a==69 || a== 73 || a==79 || a==85 || a==65+DIF || a==69+DIF || a== 73+DIF || a==79+DIF || a==85+DIF )
        printf("El caracter %c es una vocal \n", a);
    else
    printf("El caracter %c no es una letra \n", a);


    if ((b%2) == 0)
    printf("El valor ASCII de %c es par \n", b);

    if (((b-'0')%2) == 0)
    printf("El caracter %c representa un dígito par \n", b);

    if ( (c>64 && c<91) || c==97 || c==101 || c==105 || c==111 || c==117)
    printf("El caracter %c es una vocal o es mayúscula \n", c);

    if (!(a==65 || a==69 || a== 73 || a==79 || a==85 || a==65+DIF || a==69+DIF || a== 73+DIF || a==79+DIF || a==85+DIF ))
    printf("El caracter %c no es una vocal pero es letra \n", c);

}