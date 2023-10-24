#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


int suma(int num);

int main(void) {
    assert(suma(0)==0);
    assert(suma(1)==1);
    assert(suma(12)==3);
    assert(suma(100000)==1);
    assert(suma(123456)==21);
    assert(suma(-123456)==21);
    assert(suma(999999)==54);

    printf ("OK!\n");
    return 0;
}


int suma(int num){
    if(num%10 == 0 && num/10 == 0){
        return 0;
    }
    return abs(num%10) + abs(suma(num/10));
}
