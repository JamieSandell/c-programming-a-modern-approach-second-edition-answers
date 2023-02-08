/*
Rearrange the square3.c program so that the for loop initializes i, tests i, and incr-
ments i. Don't rewrite the program; in particular, don't use any multiplications.
*/

/* Prints a table of squares using an odd method */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, odd;

    printf("This program prints a table of squares.\n");
    printf("Enter the number of entries in the table: ");
    scanf("%d", &n);

    odd = 3;
    for (int i = 1, square = 1; i <= n; odd +=2, ++i)
    {
        printf("%10d%10d\n", i, square);
        square += odd;
    }

    return EXIT_SUCCESS;
}