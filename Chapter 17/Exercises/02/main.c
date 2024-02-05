/*
Write a function named duplicate that uses dynamic storage allocation to create a copy
of a string. For example, the call

p = duplicate(str);

would allocate space for a string of the same length as str, copy contents of str into
the new string, and return a pointer to it. Have duplicate return a null pointer if the
memory allocation fails.
*/

#include <stdlib.h>
#include <string.h>

void *my_malloc(size_t size);
char *duplicate(const char *source);

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

char *duplicate(const char *source)
{
    char *destination = my_malloc(strlen(source));
    strcpy(destination, source);

    return destination;
}