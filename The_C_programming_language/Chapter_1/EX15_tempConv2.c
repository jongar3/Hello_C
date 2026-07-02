#include <stdio.h>

double celsius2fahr(double celsius);

int main(){
    double temps[10] = {-20.5, -10, 0, 10, 30, 40.2, 60, 80.5, 90, 111.111};
    for (int j=0; j<10; j++) printf("Temp (ºC): %f\tTemp(ºF): %f\n", temps[j], celsius2fahr(temps[j]));

}

double celsius2fahr(double celsius){

    return (9.0/5)* celsius + 32;
}