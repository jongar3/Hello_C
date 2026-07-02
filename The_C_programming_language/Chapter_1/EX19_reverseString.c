#include <stdio.h> 
#define MAXLINE 1000

int strlen_btw(char str[]){
    int j = 0;
    while(str[j] != '\0') j++;
    return j;
}

char* reverseString(char str[]){ 
/*
better use malloc (not menitioned in the book yet o change an input: reverseString(char origen[], char result[]).
but I don't care :)
*/ 
    static char result[MAXLINE];

    int len = strlen_btw(str);
    int k = len-1;
    for (int j = 0; j < len; j++ ){
        result[j] = str[k];
        k--;
    }
    result[len] = '\0';
    return result;
}

int main(){
    int c, j;
    char string[MAXLINE];
    for(j = 0; (c=getchar()) != EOF && j < MAXLINE; j++) string[j] = c;
    string[j] = '\0';
    printf("%s", reverseString(string));
    printf("\n");
    return 0;
}