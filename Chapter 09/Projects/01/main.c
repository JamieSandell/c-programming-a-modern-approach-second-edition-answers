/*
Write a program that asks the user to enter a series of integers (which it stores in an array),
then sort the integers by calling the function selection_sort. When given an array
with n elements, selection_sort must do the following:

1. Search the array to find the largest element, then move it to the last position in the array.
2. Call itself recursively to sort the first n - 1 elements of the array.
*/

#include <stdlib.h>
#include <stdio.h>

#define LENGTH 5

void selection_sort(int numbers[], int length);

int main(void)
{
    int numbers[LENGTH] = {0, 1000, 1, 2, 2000};

    selection_sort(numbers, LENGTH);

    exit(EXIT_SUCCESS);
}

void selection_sort(int numbers[], int length)
{
    int index_largest = 0;
    int largest = 0;

    if (length == 0)
    {
        return;
    }

    for (int i = 1; i < length; i++)
    {
        if (numbers[i] > numbers[index_largest])
        {
            index_largest = i;
        }
    }

    largest = numbers[index_largest];
    numbers[index_largest] = numbers[length - 1];
    numbers[length - 1] = largest;

    selection_sort(numbers, length - 1);
}