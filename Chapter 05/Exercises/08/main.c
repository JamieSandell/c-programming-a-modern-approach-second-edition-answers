/*
The following if statement is unnecessarily complicated. Simplify it as much as possible.
(Hint: The entire statement can be replaced by a single assignment).

if (age >= 13)
    if (age <= 19)
        teenager = true;
    else
    teenager = false;
else if (age < 13)
    teenager = false;
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int age = 13;
    bool teenager = false;
    if (age >= 13 && age <= 19)
    {
        teenager = true;
    }

    printf("%s\n", teenager ? "teenager" : "not a teenager");

    return EXIT_SUCCESS;
}