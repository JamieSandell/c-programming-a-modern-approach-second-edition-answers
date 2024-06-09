/*
Write a program that reads integers from a text file whose name is given as a command-line
argument. Each line of the file may contain any number of integers (including none) sepa-
rated by one or more spaces. Have the program display the largest number in the file, the
smallest number and the median (the number closest to the middle if the integers were
sorted). If the file contains an even number of integers, there will be two numbers in the
middle; the program should display their average (rounded down). You may assume that the
file contains no more than 10,000 integers. Hint: Store the integers in an array and then sort
the array.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_INTS 10000
#define MAX_MESSAGE_LENGTH 512

int compare_ints(const void *a, const void *b);
void terminate(bool condition, const char *message);

int main(int argc, char *argv[])
{
    char message[MAX_MESSAGE_LENGTH];
    snprintf(message, MAX_MESSAGE_LENGTH, "Incorrect program usage. Example usage: main input.txt\n");
    terminate(argc != 2, message);

    FILE *fpr = fopen(argv[1], "r");
    snprintf(message, MAX_MESSAGE_LENGTH, "Error opening %s\n", argv[1]);
    terminate(fpr == NULL, message);;

    int *integers = malloc(sizeof(int) * MAX_INTS);
    snprintf(message, MAX_MESSAGE_LENGTH, "Failed to allocate memory for integers.\n");
    terminate(integers == NULL, message);

    int c;
    int *p = integers;
    int number_of_integers = 0;

    for (size_t i = 0; i < MAX_INTS && p < integers + MAX_INTS; ++i)
    {
        if ((c = fgetc(fpr)) != EOF)
        {
            snprintf(message, MAX_MESSAGE_LENGTH, "Error calling ungetc against %s\n", argv[1]);
            terminate(ungetc(c, fpr) == EOF, message);

            if (fscanf(fpr, " %d", p) == 1)
            {
                ++number_of_integers;
            }
            ++p;
        }
        else if(ferror(fpr))
        {
            snprintf(message, MAX_MESSAGE_LENGTH, "Error reading %s\n", argv[1]);
            terminate(true, message);
        }
        else if(feof(fpr))
        {
            break;
        }
    }
    
    qsort(integers, number_of_integers, sizeof(int), compare_ints);
    printf("Largest integer: %d\n", integers[number_of_integers - 1]);
    printf("Smallest integer: %d\n", integers[0]);
    int average;

    if (number_of_integers % 2 == 0)
    {
        int middle = integers[number_of_integers / 2];
        int middle2 = integers[(number_of_integers / 2) + 1];
        average = middle + middle2 / 2;
    }
    else
    {
        average = integers[(number_of_integers / 2)];
    }

    printf("Median: %d\n", average);
    return EXIT_SUCCESS;
}

int compare_ints(const void *a, const void *b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2)
    {
        return -1;
    }

    if (arg1 > arg2)
    {
        return 1;
    }

    return 0;
}

void terminate(bool condition, const char *message)
{
    if (condition)
    {
        fprintf(stderr, "%s", message);
        exit(EXIT_FAILURE);
    }
}