/*
Write the following function:

char *max_pair(int num_pairs, ...);

The arguments of max_pair are assumed to be "pairs" of integers and strings: the value of
num_pairs indicates how many pairs will follow (A pair consists of an int argument
followed by a char * argument). The function searches the integers to find the largest one;
it then returns the string argument that follows it. Consider the following call:

max_pair(5, 180, "Seinfeld", 180, "I Love Lucy",
            39, "The Honeymooners", 210, "All in the Family",
            86, "The Sopranos")

The largest int argument is 210, so the function returns "All in the Family", which
follows it in the argument list.
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *max_pair(int num_pairs, ...);

int main(void)
{
    char *p = max_pair(5, 180, "Seinfeld", 180, "I Love Lucy",
            39, "The Honeymooners", 210, "All in the Family",
            86, "The Sopranos");
    /*char *p = max_pair(6, 210, "test", 180, "Seinfeld", 180, "I Love Lucy",
            39, "The Honeymooners", 210, "All in the Family",
            86, "The Sopranos");*/
    printf("%s\n", p);
    free(p);
    return EXIT_SUCCESS;
}

char *max_pair(int num_pairs, ...)
{
    if (num_pairs <= 0)
    {
        return NULL;
    }

    va_list ap;
    va_start(ap, num_pairs);
    int largest = va_arg(ap, int);
    char *p = va_arg(ap, char *);
    int current;

    for (int i = 1; i < num_pairs; ++i)
    {
        current = va_arg(ap, int);

        if (largest < current)
        {
            largest = current;
            p = va_arg(ap, char *);
            continue;
        }

        p = va_arg(ap, char *);
    }

    va_end(ap);
    int largest_count = 0;
    va_start(ap, num_pairs);

    for (int i = 0; i < num_pairs; ++i)
    {
        current = va_arg(ap, int);

        if (current == largest)
        {
            ++largest_count;
        }

        p = va_arg(ap, char *);
    }

    va_end(ap);
    va_start(ap, num_pairs);
    size_t memory;

    for (int i = 0, current_largest_count = 0; i < num_pairs && current_largest_count < largest_count; ++i)
    {
        current = va_arg(ap, int);

        if (current == largest)
        {
            p = va_arg(ap, char *);
            memory = i == 0 ? strlen(p) + 1 : strlen(p) + 3;
            ++current_largest_count;
            continue;
        }

        p = va_arg(ap, char *);
    }

    va_end(ap);
    char *result = malloc(memory);

    if (result == NULL)
    {
        fprintf(stderr, "Error allocating memory for the result.\n");
        exit(EXIT_FAILURE);
    }

    va_start(ap, num_pairs);

    for (int i = 0, current_largest_count = 0; i < num_pairs && current_largest_count < largest_count; ++i)
    {
        current = va_arg(ap, int);
        p = va_arg(ap, char *);

        if (current == largest)
        {
            ++current_largest_count;

            if (current_largest_count == 1)
            {
                strcat(result, p);
            }
            else
            {
                strcat(result, ", ");
                strcat(result, p);
            }            
        }
    }
    
    va_end(ap);
    return result;
}