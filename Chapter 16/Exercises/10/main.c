/*
The following structures are designed to store information about objects on a graphics
screen:

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };

A point structure stores the x and y coordinates of a point on the screen. A rectangle
structure stores the coordinates of the upper left and lower right corners of a rectangle. Write
functions that perform the following operations on a rectangle structure r passed as an
argument:

(a) Compute the area of r.
(b) Compute the center of r, returning it as a point value. If either the x or y coordinate of
    the center isn't an integer, store its truncated value in the point structure.
(c) Move r by x units in the x direction and y units in the y direction, returning the modi-
    fied version of r (x and y are additional arguments to the function).
(d) Determine whether a point p lies within r, returning true or false (p is an addi-
    tion argument of type struct point).
*/

#include <stdbool.h>
#include <stdlib.h>

struct point // assumes 0,0 is the lower left of the screen, positive x is going right, positive y is going up
{
    int x;
    int y;
};

struct rectangle
{
    struct point upper_left;
    struct point lower_right;
};

int area_of_rectangle(const struct rectangle *r);
struct point center_of_rectangle(const struct rectangle *r);
struct rectangle move_rectangle(const struct rectangle *r, int x, int y);
bool point_within_rectangle(const struct rectangle *r, const struct point *p);
int length_of_rectangle(const struct rectangle *r);
int width_of_rectangle(const struct rectangle *r);

int main(void)
{
    return EXIT_SUCCESS;
}

int length_of_rectangle(const struct rectangle *r)
{
    return r->lower_right.x - r->upper_left.x;
}

int width_of_rectangle(const struct rectangle *r)
{
    return r->upper_left.y - r->lower_right.y;;
}

int area_of_rectangle(const struct rectangle *r) // (a)
{
    return width_of_rectangle(r) * length_of_rectangle(r);
}

struct point center_of_rectangle(const struct rectangle *r)
{
    int length = length_of_rectangle(r);
    int width = width_of_rectangle(r);

    struct point center = 
    {
        .x = length / 2,
        .y = width / 2
    };

    return center;
}

struct rectangle move_rectangle(const struct rectangle *r, int x, int y)
{
    struct rectangle new_rectangle = {.lower_right = r->lower_right, .upper_left = r->upper_left};
    new_rectangle.lower_right.x += x;
    new_rectangle.lower_right.y += y;
    new_rectangle.upper_left.x += x;
    new_rectangle.upper_left.y += y;

    return new_rectangle;
}

bool point_within_rectangle(const struct rectangle *r, const struct point *p)
{
    return (p->x > r->upper_left.x && p->x < r->lower_right.x && p->y < r->upper_left.y && p->y > r->lower_right.y);
}