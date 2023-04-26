/*
Write a function digit(n, k) that returns the kth digit (from the right) in n (a posi-
tive integer). For example digit(829, 1) returns 9, digit(829, 2) returns 2 and
digit(829, 3) returns 8. if k is greater than the number of digits in n, have the func-
tion return 0.
*/

#include <stdlib.h>
#include <stdio.h>

int digit(unsigned int n, unsigned int k);

int main()
{
    unsigned int n;
    unsigned int k;

    printf("Enter a number n and the kth digit from the right in n: ");
    scanf("%u %u", &n, &k);
    printf("kth digit: %d\n", digit(n, k));

    exit(EXIT_SUCCESS);
}

int digit(unsigned int n, unsigned int k)
{
    int i = 1;

    while(i < k && n >= 0)
    {
        n /= 10;
        i++;
    }

    return n == 0 ? 0 : n % 10;
}