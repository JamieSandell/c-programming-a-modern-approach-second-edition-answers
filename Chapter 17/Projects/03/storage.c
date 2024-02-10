#include <stdlib.h>
#include <stdio.h>
#include "storage.h"

/// @brief Wrapper for malloc. Exits if allocation fails.
/// @param size of memory to allocate.
/// @return void pointer to allocated memory.
void *my_malloc(size_t size)
{
    void *result = malloc(size);

    if (result == NULL)
    {
        printf("Couldn't allocate memory\n");
        exit(EXIT_FAILURE);
    }

    return result;
}

void *my_realloc(void *ptr, size_t new_size)
{
    void *result = realloc(ptr, new_size);

    if (result == NULL)
    {
        printf("Couldn't reallocate memory.\n");
        exit(EXIT_FAILURE);
    }

    return result;
}