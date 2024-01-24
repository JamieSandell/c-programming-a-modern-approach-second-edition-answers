/*
Let color be the following structure:

struct color {
    int red;
    int green;
    int blue;
};

(a) Write a declaration for a const variable named MAGENTA of type struct color
whose members have the values 255, 0 and 255, respectively.

(b) (C99) Repeat part (a), but use a designated initializer that doesn't specify the value of
green, allowing it to defaul to 0.
*/

#include <stdlib.h>

struct color
{
    int red;
    int green;
    int blue;
};

int main(void)
{
    const struct color MAGENTA = {255, 0, 255}; // (a)
    const struct color MAGENTA_C99 = {.red = 255, .blue = 255};

    return EXIT_SUCCESS;
}