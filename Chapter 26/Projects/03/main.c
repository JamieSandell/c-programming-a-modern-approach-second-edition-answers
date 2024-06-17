/*
Write a program that uses the clock function to measure how long it takes qsort to sort
an array of 1000 integers that are originally in reverse order. Run the program for arrays of
10000 and 100000 integers as well.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_INTS 100000

int comparator(const void *a, const void *b);

int main(void)
{
    int *numbers = malloc(NUM_OF_INTS * sizeof(int));

    if (numbers == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for %d integers.\n", NUM_OF_INTS);
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < NUM_OF_INTS; ++i)
    {
        numbers[i] = NUM_OF_INTS - i;
    }

    clock_t time_req = clock();
    qsort(numbers, NUM_OF_INTS, sizeof(int), comparator);
    time_req = clock() - time_req;
    /*
    for (int i = 0; i < NUM_OF_INTS; ++i)
    {
        printf("%d\n", numbers[i]);
    }
    */
    free(numbers);
    printf("Processor time taken for reversing %d ints: %f seconds.\n", NUM_OF_INTS, (float)time_req / CLOCKS_PER_SEC);

    return EXIT_SUCCESS;
}

int comparator(const void *a, const void *b)
{
    int x = *((const int *)a);
    int y = *((const int *)b);

    if (x < y)
    {
        return -1;
    }
    
    if (x > y)
    {
        return 1;
    }

    return 0;
}