/* atof: convert string s to double + implement scientific notation */
#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]) {

    double val, power;
    int i, sign;
    for (i = 0; isspace(s[i]); i++) /* skip white space */; 
        sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') i++;
        for (val = 0.0; isdigit(s[i]); i++)
            val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.') i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        double exp = atof(&s[i]);
        return sign * val / power * pow(10, exp);
    }
    return sign * val / power;
}

void main() {
    char str1[] = "123.45";
    char str2[] = "-67.89e2";
    char str3[] = "3.14E-1";
    char str4[] = "48.1e36";

    printf("String: %s, Converted to double: %f\n", str1, atof(str1));
    printf("String: %s, Converted to double: %f\n", str2, atof(str2));
    printf("String: %s, Converted to double: %f\n", str3, atof(str3));
    printf("String: %s, Converted to double: %f\n", str4, atof(str4));

}
