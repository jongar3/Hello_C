#include <stdio.h>

unsigned int invert(unsigned int x, int n, int p){
/*Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.*/
    unsigned int mask = ~(~0 << n);

    x = x >> (p + 1 - n);
    return (x ^ mask) & mask;
}

int main(){

    printf("%d\n",invert(0b11010000, 4, 7));

}