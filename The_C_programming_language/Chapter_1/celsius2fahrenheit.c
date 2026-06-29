#include <stdio.h>

/*
    this is a line block comment :O
*/

int main(){
    int lower = 0; //lower limit in celsius
    int upper = 100; //Upper   "   "    "
    int step = 10;
s
    int celsius = lower;
    float fahr;
    printf("ºC\tºF\n"); // A "HEAD"
    while(celsius <= upper){ //the lion does not concern himself with for loops
        fahr = (9.0/5)* celsius + 32;
        printf("%3d\t%.2f\n", celsius, fahr);
        celsius += step;
    }
}

/*COMPACETED:

#include <stdio.h>
#define LOWER 0 
#define UPPER 300 
#define STEP 20 

main() {
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

*/