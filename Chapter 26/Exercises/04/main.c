/*
Write a function named display that takes any number of arguments. The first argument
must be an integer. The remaining arguments will be strings. The first argument specifies
how many strings the call contains. The function will print the strings on a single line, with
adjacent strings separated by one space. For example, the call

display(4, "Special", "Agent", "Dale", "Cooper");

will produce the following output:

Special Agent Dale Cooper
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void my_dislay(int n, ...);

int main(void)
{
    my_dislay(4, "Special", "Agent", "Dale", "Cooper");
    return EXIT_SUCCESS;
}

void my_dislay(int n, ...)
{
    va_list ap;
    char *p;
    va_start(ap, n);

    for (size_t i = 0; i < (size_t)n; ++i)
    {
        p = va_arg(ap, char *);
        printf("%s%s", p, i == 3 ? "\n" : " ");
    }
    
    va_end(ap);
}