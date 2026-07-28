#include <stdio.h>
#include "../include/getch.h"

#define BUFSIZE 100

extern char buf[]; 
extern int bufp;

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: demasiados caracteres\n");
    else
        buf[bufp++] = c;
}