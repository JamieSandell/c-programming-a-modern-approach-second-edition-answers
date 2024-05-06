/*
Write a call of printf that prints

1 widget
if the widget variable (of type int) has the value 1, and

n widgets

otherwise, where n is the value of widget. You are not allowed to use the if statement or
any other statement; the answer must be a single call of printf.
*/

#include <stdio.h>
#include <stdlib.h>

#define widgets 1

int main(void)
{
    printf("%d widget%s", widgets, widgets == 1 ? "\n" : "s\n");

    return EXIT_SUCCESS;
}