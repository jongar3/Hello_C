#include <string.h>
#include <stdio.h> 
#include <stdlib.h>


int main(int argc, char *argv[]){
    printf("\n");
    for (int j=1; j< argc; j++) printf("%s ", argv[j]);
    printf("\n");
    return 0;
}