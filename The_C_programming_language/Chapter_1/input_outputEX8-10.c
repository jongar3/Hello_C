#include <stdio.h>
#include <stdbool.h> //bool is not part from the 'vanilla c' :o

int main(){

    long pos;
    int ntab, nl, nb , c;
    bool space_flag = false;

    for(pos = 0; (c=getchar()) != EOF ; pos++){
        if (c == ' '){
            nb++;
            if (!space_flag) putchar(c);
            space_flag= true;

        }else space_flag= false;

        if(c == '\n') 
            nl++;
        else if(c == '\t'){
            ntab++;
            putchar('\\');
            c='t';
        }

        if (!space_flag) putchar(c);
    }

    printf("\n--------------\n Number of letters: %ld\n", pos);
    printf("Number of lines: %d\n", nl);
    printf("Number of tabs: %d\n" , ntab);
    
}