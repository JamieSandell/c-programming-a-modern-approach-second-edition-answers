/*
Modify the upc.c program of Section 4.1 so that it checks whether a UPC is valid. After
the user enters a UPC, the program will display either VALID or NOT vALID.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5,
        first_sum, second_sum, total;

    printf("Enter the first 11 digits of a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &d, &i1, &i2, &i3, &i4, &i5, &j1, &j2, &j3, &j4, &j5);
    first_sum = d + i2 + i4 + j1 +j3 + j5;
    second_sum = i1 + i3 + i5 +j2 +j4;
    total = 3 * first_sum + second_sum;

    int check_digit = 9 - ((total - 1) % 10);
    printf("Check digit: %d\n", check_digit);

    if (check_digit != j5)
    {
        printf("INVALID\n");
        return EXIT_FAILURE;
    }
    printf("VALID\n");
    return EXIT_SUCCESS;
}