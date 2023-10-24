#include <stdio.h>
#include <assert.h>

int palindromo(char *s);

int main(void) {

    assert(palindromo("a")==1);
    assert(palindromo("")==1);
    assert(palindromo("neuquen")==1);
    assert(palindromo("abba")==1);
    assert(palindromo("12345654321")==1);
    assert(palindromo("abab")==0);
    assert(palindromo("123456")==0);


    printf ("OK!\n");
    return 0;
}


int palindromo(char *s){

}