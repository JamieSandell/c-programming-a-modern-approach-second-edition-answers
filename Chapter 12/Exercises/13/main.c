/*
Section 8.2 had a program fragment in which two nested for loops initialized the array
ident for use as an identity matrix. Rewrite this code, using a single pointer to step
through the array one element at a time. Hint: Since we won't be using row and col index
variables, it won't be easy to tell where to store 1. Instead, we can use the fact that the first
element of the array should be 1, the next N elements should be 0, the next element should
be 1 and so forth. Use a variable to keep track of how many consecutive 0s have been
stored; when the count reaches N, it's time to store 1.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 3

int main(void)
{
    int ident[LENGTH][LENGTH];    
    int *p = ident[0];  
    int *end = ident[0] + LENGTH * LENGTH;
    int consecutive_zeros = 0;

    *p = 1;
    printf("%d", *p++);

    while (p++ < end)
    {
        if (consecutive_zeros == LENGTH)
        {
            *p = 1;
            consecutive_zeros = 0;
        }
        else
        {
            *p = 0;
            consecutive_zeros++;
        }

        printf("%d", *p);

        if (((uintptr_t)end - (uintptr_t)p) % LENGTH == 0)
        {
            printf("\n");
        }
    }

    exit(EXIT_SUCCESS);
}