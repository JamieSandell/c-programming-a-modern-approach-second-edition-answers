/*
Let a be an array of 100 integers. Write a call of qsort that sorts only the last 50 elements
in a. (You don't need to write the comparison function).
*/

#include <stdio.h>
#include <stdlib.h>

#define CMP_START_INDEX 49
#define SIZE 100
#define NUMBER_OF_ELEMENTS SIZE - CMP_START_INDEX + 1

int cmp_ascending(const void *a, const void *b);
void print_array(int start_index, int n, const int array[]);

int main(void)
{
    int a[SIZE];

    printf("List before sorting: ");
    print_array(CMP_START_INDEX, NUMBER_OF_ELEMENTS, a);
    qsort(&a[CMP_START_INDEX], NUMBER_OF_ELEMENTS, sizeof(int), &cmp_ascending);
    printf("List after sorting: ");
    print_array(CMP_START_INDEX, NUMBER_OF_ELEMENTS, a);

    return EXIT_SUCCESS;
}

int cmp_ascending(const void *a, const void *b)
{
    const int *p1 = (int *)a;
    const int *p2 = (int *)b;

    if (*p1 == *p2)
    {
        return 0;
    }
    else if (*p1 > *p2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void print_array(int start_index, int n, const int array[])
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", array[start_index++]);
    }

    printf("\n\n");
}