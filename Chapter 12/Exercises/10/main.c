/*
Modify the find_middle function of Section 11.5 so that it uses pointer arithmetic to
calculate the return value.
*/

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 5

int find_middle(int a[], int n);

int main(void)
{
    int a[LENGTH] = {1, 2, 3, 4, 5};

    printf("Middle value of a[] is: %d\n", find_middle(a, LENGTH));

    exit(EXIT_SUCCESS);
}

int find_middle(int a[], int n)
{
    return *(a + n / 2);
}