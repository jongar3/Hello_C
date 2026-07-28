#include <stdio.h>
#include "../include/calc.h"

#define MAXVAL 100

static int sp = 0;          
static double val[MAXVAL]; 

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: pila llena, no se puede apilar %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    
    printf("error: pila vacia\n");
    return 0.0;
}