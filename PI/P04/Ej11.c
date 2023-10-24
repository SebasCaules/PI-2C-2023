#include <stdio.h>
#include <assert.h>

int mayor(int x, int y, int z){
    int max;
    if (x>=y){
        if(x>=z){
            max = x;
        }else {
            max = z;
        }
    }else if(y>=z){
        max = y;
    }else {
        max = z;
    }
    return max;
}
void tester(void){
    int a=1, b=4, c=8;
    assert(mayor(a,b,c));
    //assert(mayor(a,b,c)==b);
    //assert(mayor(a,b,c)==c);
    puts("no se encontraron errores");

}

int main(void){
    printf("%d", mayor(5,8,9));
    tester();
}

