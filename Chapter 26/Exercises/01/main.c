/*
Rewrite the max_int function so that, instead of passing the number of integers as the first
argument, we must supply 0 as the last argument. Hint: max_int must have at least one
"normal" parameter, so you can't remove the parameter n. Instead, assume that it represents
one of the numbers to be compared.
*/

#include <stdarg.h>
#include <stdlib.h>

int max_int(int n, ...);

int main(void)
{
    return EXIT_SUCCESS;
}

int max_int(int n, ...)
{
    va_list ap;
    int current, largest;

    va_start(ap, n);
    largest = va_arg(ap, int);

    for (;;)
    {
        current = va_arg(ap, int);

        if (current == 0)
        {
            break;
        }

        if (current > largest)
        {
            largest = current;
        }
    }

    va_end(ap);
    return largest;
}