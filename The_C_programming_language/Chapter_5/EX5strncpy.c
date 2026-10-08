#include <stddef.h> // For size_t
#include <stdio.h>

char *my_strncpy(char *s, const char *t, size_t n)
{
    s[n]='\0';
    while (n > 0 && (*s = *t) != '\0') {
        s++;
        t++;
        n--;
    }
    
    while (n > 0) {
        *s++ = '\0';
        n--;
    }

    return s;
}
int main() {
    char dest[20];
    const char *src = "Hello, World!";
    size_t n = 5;

    my_strncpy(dest, src, n);
    printf("Copied string: %s\n", dest); 
    return 0;
}