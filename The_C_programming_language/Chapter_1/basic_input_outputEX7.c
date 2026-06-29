#include <stdio.h>
int main() {
    printf("EOF is equal to: %d\n", EOF);
    printf("Example of use: echo 'Hello World!' | ./a.out\n");
    int c;
    while ((c = getchar()) != EOF) {
        putchar(c); 
        printf("%c",c);
    }
}