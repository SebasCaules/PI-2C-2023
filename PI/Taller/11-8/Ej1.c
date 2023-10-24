#include <stdio.h>

int main(){
    unsigned char var, var1, var2, var3, var4;
    var = getchar();
    var1 = var >> 6 & 0x03;
    var2 = var >> 4 & 0x03;
    var3 = var >> 2 & 0x03;
    var4 = var & 0x03;
    printf("%x queda, %x, %x, %x, %x\n", var, var1, var2, var3, var4);
    return 0;
}