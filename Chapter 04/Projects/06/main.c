/*
European countries use a 13-digit code, known as a European Article Number (EAN)
instead of the 12-digit Universal Product Code (UPC) found in North America. Each EAN
ends with a check digit, just as a UPC does. The technique for calculating the check digit is
also similar:
    Add the second, fourth, sixth, eigth, tenth, and twelth digits.
    Add the first, third, fifth, seventh, ninth and eleventh digits.
    Multiply the first sum by 3 and add it to the second sum.
    Subtract 1 from the total.
    Compute the remainder when the adjusted total is divide by 10.
    Subtract the remainder from 9.

...

Enter the first 12 digits of an EAN: 869148426000
Check digit: 8
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12,
        first_sum, second_sum, total;

    printf("Enter the first 12 digits of an EAN: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11, &i12);

    first_sum = i2 + i4 + i6 + i8 + i10 + i12;
    second_sum = i1 + i3 + i5 + i7 + i9 + i11;
    total = first_sum * 3 + second_sum;
    total -= 1;
    printf("Check digit: %1d\n", 9 - (total % 10));

    return EXIT_SUCCESS;
}