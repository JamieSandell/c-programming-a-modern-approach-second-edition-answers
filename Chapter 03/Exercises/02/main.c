/*
Write calls of printf that display a float x in the following formats.

(a) Exponential notation; left-justified in a field of size 8; one digit after the decimal
    point.
(b) Exponential notation; left-justified in a field of size 8; three digits after the decimal
    point.
(c) Fixed decimal notation; right-justified in a field of size 6; no digits after the decimal
    point.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x;
    printf("Enter a number: ");
    scanf("%f", &x);
    printf("%-8.1e\n", x);
    printf("%-8.3e\n", x);
    printf("%6.0f\n", x);

    return EXIT_SUCCESS;
}