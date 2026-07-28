#include <stdio.h>

#define SWAP(t, x, y) { \
    t _temp = x;        \
    x = y;              \
    y = _temp;          \
}

main() {
    int a = 5, b = 10;
    printf("Before: a = %d, b = %d\n", a, b);
    SWAP(int, a, b);
    printf("After: a = %d, b = %d\n\n", a, b);
    return 0;
}