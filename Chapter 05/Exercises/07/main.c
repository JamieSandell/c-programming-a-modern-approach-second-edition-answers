/*
What does the following statement print if i has the value 17? What does it print if i has the
value -17?

printf("%d\n", i >= 0 ? i : -i);

It will print 17.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = -17;

    printf("%d\n", i >= 0 ? i : -i);

    return EXIT_SUCCESS;
}