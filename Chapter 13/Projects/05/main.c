/*
Write a program named sum.c that adds up its command-line arguments, which are
assumed to be integers. Running the program by typing

sum 8 24 62

should produce the following output:

Total: 94

Hint: Use the atoi function to convert each command-line argument from string form to
integer form.
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int sum = 0;

    if (argc < 3)
    {
        printf("Error: too few arguments. Enter at least two numbers, e.g. 2 4\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++)
    {
        sum += atoi(argv[i]);
    }

    printf("Total: %d\n", sum);

    exit(EXIT_SUCCESS);
}