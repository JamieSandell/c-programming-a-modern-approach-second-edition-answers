/*
Write a program that tests the atexit function. The program should have two functions (in addition to main), one of which prints That's
all,  and the other folks!. Use the atexit function to register both to be called at program termination. Make sure they're called in the
proper order so that we see the message That's call, folks! on the screen.
*/

#include <stdio.h>
#include <stdlib.h>

void print_folks(void);
void print_thats_all(void);

int main(void)
{
    if (!atexit(print_folks) && !atexit(print_thats_all))
    {
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}

void print_folks(void)
{
    printf(" folks!\n");
}

void print_thats_all(void)
{
    printf("That's all");
}