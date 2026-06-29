#include <stdio.h>
#define TOTAL_LETTERS 26
#define MAX_LENGHT_OF_BARS 120.0
int main(){
    int n_coincidences[TOTAL_LETTERS];
    long nl=0;
    int c;
    for (int j=0; j<TOTAL_LETTERS; j++) n_coincidences[j] = 0;

    while((c=getchar()) != EOF){
        if ((c>= 'a') && (c<= 'z')){ //I DO NOT CONCERN ABOUT CAPITAL LETTERS
            nl++;
            n_coincidences[c-'a']++;
        }

    }

    //PRINT HISTOGRAM
    int k = 0; 
    for (int j=0; j<TOTAL_LETTERS; j++){
        printf("%c:\t",'a'+ j);
        for (k=0; k < MAX_LENGHT_OF_BARS*((double)n_coincidences[j]/nl); k++){
            printf("-");
        }
        printf("\n");

    }

    return 0;
}