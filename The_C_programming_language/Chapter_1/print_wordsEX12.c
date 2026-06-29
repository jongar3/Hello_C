#include <stdio.h>
#define IN 0
#define OUT 1

int main(){
    short state = IN;
    int c;
    while((c=getchar()) != EOF){

        if (c == ' ' || c  == '\t' || c == '\n'){
            if (state == IN){
                state = OUT;
                printf("\n");
            } 
        }else if(state == OUT){
            state = IN;
        }
  
        if(state == IN && !(c == ' ' || c  == '\t' || c == '\n')) putchar(c);

    }
    printf("\n");
}

/*RESULT of: cat example_text.txt | ./a.out 
hello
world
what's
up?
this
is
a
test
a
small
one...
*/