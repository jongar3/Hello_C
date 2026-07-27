#include <string.h>
#include <stdio.h>
#include <limits.h>

void reverse(char s[]) {
    int i, j;
    char c;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[]) {
    int i, sign;
    unsigned int u;

    if ((sign = n) < 0)
        u = -(unsigned int)n;
    else
        u = (unsigned int)n;

    i = 0;
    do {
        s[i++] = u % 10 + '0';
    } while ((u /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main(void)
{
    char buffer[32];
    int tests[] = {INT_MIN, INT_MAX, 0, -12345, 12345, -1, 1};
    int count = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < count; i++) {
        itoa(tests[i], buffer);
        printf("%d  ->  \"%s\"\n", tests[i], buffer);
    }

    return 0;
}