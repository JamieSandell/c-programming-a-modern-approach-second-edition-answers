/*
Write the following function:

char *vstrcat(const char *first, ...);

All arguments of vstrcat are assumed to be strings, except for the last argument, which
must be a null pointer (cast to char * type). The function returns a pointer to a dynamically
allocated string containing the concatenation of the arguments. vstrcat should return a
null pointer if not enough memory is available. Hint: Have vstrcat go through the argu-
ments twice: once to determine the amount of memory required for the returned string and
once to copy the arguments into the string.
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *vstrcat(const char *first, ...);

int main(void)
{
    char *result = vstrcat("Hi, ", "my ", "name ", "is ", "Jamie.", (char *)NULL);
    printf("%s\n", result);
    free(result);
    return EXIT_SUCCESS;
}

char *vstrcat(const char *first, ...)
{
    va_list ap;
    va_start(ap, first);
    const char *p = first;
    size_t memory = strlen(p) + 1;

    while (p != NULL)
    {
        memory += strlen(p) + 1;
        p = va_arg(ap, const char *);
    }

    va_end(ap);

    char *result = malloc(memory);

    if (result == NULL)
    {
        return result;
    }

    va_start(ap, first);
    p = first;

    while (p != NULL)
    {
        strcat(result, p);
        p = va_arg(ap, const char *);
    }

    va_end(ap);
    return result;
}