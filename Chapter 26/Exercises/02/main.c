/*
Write a simplified version of printf in which the only conversion specification is %d, and
all arguments after the first are assumed to have int type. If the function encounters a %
character that's not immediately followed by a d character, it should ignore both characters.
The function should use calls of putchar to produce all output. You may assume that the
format string doesn't contain escape sequences.
*/

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void my_printf(const char *format, ...);
void print_int(int n);

int main(void)
{
    my_printf("Hi, my name is Jamie and I'm %d years old.", 37);

    return EXIT_SUCCESS;
}

void my_printf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    bool start_of_format_specifier = false;

    for (const char *c = format; *c != '\0'; ++c)
    {
        if (!start_of_format_specifier && *c == '%')
        {
            start_of_format_specifier = true;
            continue;
        }

        if (start_of_format_specifier == true)
        {
            start_of_format_specifier = false;

            if (*c == 'd')
            {
                print_int(va_arg(ap, int));
            }

            continue;
        }

        putchar(*c);
    }    

    va_end(ap);
}

void print_int(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }

    if (n / 10)
    {
        print_int(n / 10);
    }

    putchar(n % 10 + '0');
}