#include <stdio.h>

int
main(void)
{
    // Poner int a, b, c = 5 no declara ni a "b" ni "c" como = 5
 		int a = 5;
        int b = 5; 
        int c = 5;
 		a = b + c;
 		printf("%u", a);
 		return 0;
}
