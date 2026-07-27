/*REFACTOR:
int lower(int c){
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}*/
#include <stdio.h>

int lower(int c){
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A':c;
}

int main(){
    int c;
    while ((c = getchar()) != EOF) {
        putchar(lower(c));
    }

}