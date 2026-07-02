#include <stdio.h>

int main() {
    // --- Compute Signed Int Range ---
    int max_int = 0;
    int i = 1;
    
    while (i > 0) {
        max_int = i;
        i++;
    }
    
    int min_int = -max_int - 1;

    printf("Computed int range: %d to %d\n", min_int, max_int);

    unsigned int max_uint = 0;
    unsigned int j = 1;

    while (j > 0) {
        max_uint = j;
        j++;
    }
    
    printf("Computed unsigned int range: 0 to %u\n", max_uint);

    // --- Compute short Signed Int Range ---
    int max_int_short = 0;
    short int l = 1;
    
    while (l > 0) {
        max_int_short = l;
        l++;
    }
    
    int min_int_short = -max_int_short - 1;

    printf("Computed short int range: %d to %d\n", min_int_short, max_int_short);


    // --- Compute long Signed Int Range ---
    long max_int_long = 1;
    long prev;

    while (max_int_long > 0) {
        prev = max_int_long;
        max_int_long *= 2;      /* doubling instead of +=1 */
    }

    long min_int_long = -max_int_long - 1;
    printf("Computed long int range: %ld to %ld\n", min_int_long, max_int_long);

    return 0;

}