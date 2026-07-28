#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/calc.h"
#include "../include/getch.h"

#define MAXOP 100

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    printf("Calculadora RPN (Notacion Polaca Inversa)\n");
    printf("Escribe expresiones como '1 2 +' o '10 2 /'\n\n");

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: division por cero\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: comando desconocido %s\n", s);
            break;
        }
    }
    return 0;
}

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    
    if (!isdigit(c) && c != '.')
        return c;

    i = 0;
    if (isdigit(c)) 
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')   
        while (isdigit(s[++i] = c = getch()))
            ;
            
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}