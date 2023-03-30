/*
Write a program that prints the values of sizeof(int), sizeof(short),
sizeof(long), sizeof(float), sizeof(double) and sizeof(long dou-
ble).
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("sizeof(int): %llu bytes\n", sizeof(int));
    printf("sizeof(short): %llu bytes\n", sizeof(short));
    printf("sizeof(long): %llu bytes\n", sizeof(long));
    printf("sizeof(float): %llu bytes\n", sizeof(float));
    printf("sizeof(double): %llu bytes\n", sizeof(double));
    printf("sizeof(long double): %llu bytes\n", sizeof(long double));

    return EXIT_SUCCESS;
}