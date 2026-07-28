#include <stdio.h>
#include "../include/getch.h"

#define BUFSIZE 100


char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}