#include <stdio.h>
#define CUBO(x)  ((x) * (x) * (x))


int cubo (int num);


int
main(void)
{
    int a=3, b, c, d, e, f;


    b = CUBO( ++a );
    c = CUBO( a++ );
    d = 3;
    e = cubo ( ++d );
    d = 3;
    f = cubo ( d++ );
    printf("%d \n",b);
    printf("%d ",c);
    printf("%d ",d);
    printf("%d ",e);
    printf("%d ",f);

    return 0;
}


int
cubo ( int num )
{
    return num * num * num;
}

