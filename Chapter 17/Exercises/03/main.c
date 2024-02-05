/*
Write the following function:

int *create_array(int n, int initial_value);

The function should return a pointer to a dynamically allocated int array with n members,
each of which is initialized to initial_value. The return value should be NULL if the
array can't be allocated.
*/

#include <stdlib.h>
#include <string.h>

void *my_malloc(size_t size);
int *create_array(int n, int initial_value);

int main(void)
{
    return EXIT_SUCCESS;
}

void *my_malloc(size_t size)
{
    void *result = malloc(size);

    if (malloc == NULL)
    {
        exit(EXIT_FAILURE);
    }

    return result;
}

int *create_array(int n, int initial_value)
{
    int *numbers = my_malloc(sizeof(int) * n);
    //memset(numbers, initial_value, sizeof(int) * n); // We can't use memset because it sets each bytes. Works for char arrays as a char is 1 byte, but ints are bigger.
    for (int i = 0; i < n; ++i)
    {
        numbers[i] = initial_value;
    }

    return numbers;
}