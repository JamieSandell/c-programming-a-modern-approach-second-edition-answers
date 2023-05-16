/*
Assume that the following array contains a week's worth of hourly temperature readings,
with each row containing the readings for one day:

int temperatures[7][24];

Write a statement that uses the search function (see Exercise 7) to search the entire
temperatures array for the value 32.

bool result = search(temperatures[0], 7 * 24, 32);
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 2

bool search(const int a[], int n, int key);

int main(void)
{
    int a[LENGTH][LENGTH] = {{1, 2}, {3, 32}};
    int key = 32;

    if (search(a[0], LENGTH * LENGTH, key))
    {
        printf("Found key %i in a[]\n", key);
    }
    else
    {
        printf("Did not find key %i in a[]\n", key);
    }

    exit(EXIT_SUCCESS);
}

bool search(const int a[], int n, int key)
{
    for (const int *p = a; p < a + n; p++)
    {
        if (*p == key)
        {
            return true;
        }
    }

    return false;
}