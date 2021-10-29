/*
Write a program that declares several int and float variables - without initializing them - and then prints their values.
Is there any pattern to their values? (Usually there isn't.)

No pattern.
*/

#include <stdio.h>

int main(void)
{
    int x, y, z;
    float a, b, c;

    printf("%d, %d, %d\n%.2f, %.2f, %.2f\n", x, y, z, a, b, c);
    return 0;
}