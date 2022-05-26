/*
For each of the following pairs of scanf format strings, indicate whether or not the two strings are equivalent.
If they're not, show how they can be distinguished.

(a) "%d"       versus " %d"
(b) "%d-%d-%d" versus "%d -%d -%d"
(c) "%f"       versus "%f "
(d) "%f,%f"    versus "%f, %f"

(a) These are equivalent. The whitespace is ignored and then an integer scanned for.
(b) These are not equivalent. The one on the right would work if the input was in the format of the one on the left.
    It would match a number, skip none or more whitespace, match the - and so on and so forth.
    The one on the left would not work if the input was in the format of the one on the right.
    It would match a number and then attempt to match the whitespace with a -.
(c) These are not equivalent. The one on the right has a trailing whitespace so a user must type a character other than whitespace
    (newline is a whitespace) before the input is complete.
(d) These are not equivalent. The one on the right would if the inpt as in the format of the one on the left.
    It would match a float, match a comma, ignore none or more whitespace and then match a float.
    The one on the left would not work if the input was in the format of the one on the right.
    It woulc match a float, match a comma and then attempt to match a whitespace with a float.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    printf("Enter real number in the format \" %%d\" to see that \"%%d\" and \" %%d\" are equivalent: ");
    scanf(" %d", &num1);
    printf("num1: %d\n\n", num1);

    /* Causes the program to crash
    int num2, num3, num4;
    printf("Enter three real numbers in the format  \"%%d -%%d -%%d\" to see that\n\"%%d-%%d-%%d\" and \"%%d -%%d -%%d\" are not equiavelent: ");   
    scanf("%d-%d-%d", &num2, &num3, &num4);
    printf("num1: %d, num2: %d, num3: %d\n\n", num2, num3, num4); */

    /* comment out to see
    float num5;
    printf("Enter a float in the format \"%%f \" to see that \"%%f\" and \"%%f \" are not equivalent: ");
    scanf("%f ", &num5);
    printf("num5: %f", num5);
    */

    float num6, num7;
    printf("Enter two floats in the format \"%%f, %%f\" to see that \"%%f,%%f\" and \"%%f, %%f\" are equivalent: ");
    scanf("%f,%f", &num6, &num7);
    printf("num6: %f, num7: %f\n", num6, num7);

    return EXIT_SUCCESS;
}