/*
Suppose that the following declarations are in effect:

struct point { int x, y; };
struct rectangle {struct point upper_left, lower_right; };
struct rectangle *p;

Assume that we want p to point to a rectangle structure whose upper left corner is at
(10, 25) and whose lower right corner is at (20, 15). Write a series of statements that allocate
such a structure and initialize it as indicated.
*/

#include <stdlib.h>
#include <string.h>

struct point { int x, y; };
struct rectangle {struct point upper_left, lower_right; };

void *my_malloc(size_t size);

int main(void)
{
    struct rectangle *p = my_malloc(sizeof(*p));
    struct rectangle my_rectangle = {
        .upper_left.x = 10,
        .upper_left.y = 25,
        .lower_right.x = 25,
        .lower_right.y = 15
    };

    p = &my_rectangle;

    return EXIT_SUCCESS;
}

void *my_malloc(size_t size)
{
    void *result = malloc(size);

    if (malloc == NULL)
    {
        exit(EXIT_FAILURE);
    }

    return result;
}