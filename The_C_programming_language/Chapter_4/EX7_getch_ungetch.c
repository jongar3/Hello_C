#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

// Búfer compartido y su índice 
char buf[BUFSIZE]; /* Búfer para ungetch */
int bufp = 0;      /* Próxima posición libre en buf */

//
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// ungetch: empuja un carácter de vuelta al búfer de entrada 
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: demasiados caracteres\n");
    else
        buf[bufp++] = c;
}

// ungets: devuelve una cadena completa a la entrada usando ungetch
void ungets(const char s[])
{
    int i = strlen(s);
    while (i > 0) {
        ungetch(s[--i]);
    }
}

/* Main de prueba */
int main(void)
{
    printf("1. Empujando la cadena \"Hola\" al bufer con ungets()...\n");
    ungets("Hola");

    printf("2. Leyendo los caracteres uno a uno usando getch():\n");
    int c;

    for (int i = 0; i < 4; i++) {
        c = getch();
        printf("   Carácter %d leido: '%c'\n", i + 1, c);
    }

    printf("\n3. Ahora escribe algo en el teclado y presiona Enter (para probar la entrada directa):\n");
    
    /* Como el búfer buf ya está vacío, getch() llamará a getchar() para pedir datos al teclado */
    c = getch();
    printf("   Leido desde el teclado: '%c'\n", c);

    return 0;
}