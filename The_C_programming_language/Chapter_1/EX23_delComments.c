#include <stdio.h>

int main() {
    int c;
    int prev = 0;           
    int in_line_comment = 0; 
    int in_block_comment = 0;

    while ((c = getchar()) != EOF) {
        if (in_line_comment) {
            if (c == '\n') {
                in_line_comment = 0;
                putchar(c); 
            }
        } 
        else if (in_block_comment) {
            if (prev == '*' && c == '/') {
                in_block_comment = 0;
                c = 0;
            }
        } 
        else {
            if (prev == '/' && c == '/') {
                in_line_comment = 1;
                c = 0;
            }
            else if (prev == '/' && c == '*') {
                in_block_comment = 1;
                c = 0;        
            }
            else {
                if (prev == '/') {
                    putchar('/');   
                }
                if (c != '/') {
                    putchar(c);  
                }
            }
        }
        prev = c;
    }
    return 0;
}