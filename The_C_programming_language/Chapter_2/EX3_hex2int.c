#include <stdio.h>
#include <string.h>
#define HEX "A3B1"


int hex2int(const char hex[]){
    int result = 0;
    int c;
    for (int j = 0; hex[j] != '\0'; j++) {
        int value;
        c= hex[j];
        int totalnum= strlen(hex);
        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;
        } else {
            // Invalid character for hexadecimal
            return -1; // or handle error as needed
        }
        result = result * 16 + value;
    }
    return result;
}

int main() {
    int decimalValue = hex2int(HEX);
    if (decimalValue != -1) {
        printf("Hexadecimal: %s\nDecimal: %d\n", HEX, decimalValue);
    } else {
        printf("Invalid hexadecimal input.\n");
    }
    return 0;
}