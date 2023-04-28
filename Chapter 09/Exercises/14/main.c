/*
The following function is supposed to return true if any element of the array a has the
value 0 and false if all elements are nonzero. Sadly, it contains an error. Find the error
and show how to fix it:

bool has_zero(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        if (a[i] == 0)
            return true;
        else
            return false;
}
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define LENGTH 3

bool has_zero(int a[], int n);

int main(void)
{
    int a[] = {1, 0, 1};

    if (has_zero(a, LENGTH))
    {
        printf("Has zero.\n");
    }
    else
    {
        printf("Does not have zero.\n");
    }

    exit(EXIT_SUCCESS);
}

/*
The error was that it would return false even if there were non-zero elements because of the else statement.
e.g. a[] = {1, 0, 1};
would return false despite not all elements being nonzero.
*/
bool has_zero(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            return true;
        }
    }

    return false;
}