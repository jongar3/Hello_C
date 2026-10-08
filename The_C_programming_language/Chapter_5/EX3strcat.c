#include <string.h>
#include <stdio.h>
#define MAX_SIZE 40
void mi_strcat(char* s, char* t ){


    int ls = strlen(s);
    int j=0;
    while(s[ls + j] = t[j]) j++;
}

int main(){
    char end[MAX_SIZE] = "World!";
    char beg[MAX_SIZE] = "Hello "; 
    mi_strcat(beg, end);
    printf("Concatenated string: %s\n", beg);
    return 0;

}