/*
Let shape be the structure tag declared in Exercise 13. Write functions that perform the
following operations on a shape structure s passed as an argument:

(a) Compute the area of s.
(b) Move s by x units in the x direction and y units in the y direction, returning the modi-
    fied version of s (x and y are additional arguments to the function).
(c) Scale s by a factor of c (a double value), returning the modified version of s (c is an
    additional argument to the function).
*/

#include <stdlib.h>

#define RECTANGLE 0
#define CIRCLE 1
#define PI 3.14

struct point
{
    int x;
    int y;
};

struct shape {
    int shape_kind;            /* RECTANGLE or CIRCLE */
    struct point center;       /* coordinates of center */
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
} s;

int area(const struct shape *s);
struct shape move(const struct shape *s, int x, int y);
struct shape scale(const struct shape *s, double c);
void copy(const struct shape *src, struct shape *dest);

int main(void)
{
    return EXIT_SUCCESS;
}

int area(const struct shape *s) // (a)
{
    if (s->shape_kind == RECTANGLE)
    {
        return s->u.rectangle.height * s->u.rectangle.width;
    }
    return PI * s->u.circle.radius * s->u.circle.radius;
}

struct shape move(const struct shape *s, int x, int y) // (b)
{
    struct shape result;
    copy(s, &result);
    result.center.x += x;
    result.center.y += y;
    return result;
}

struct shape scale(const struct shape *s, double c) // (c)
{
    struct shape result;
    copy(s, &result);

    if (result.shape_kind == RECTANGLE)
    {
        result.u.rectangle.height *= c;
        result.u.rectangle.width *= c;
    }
    else
    {
        result.u.circle.radius *= c;
    }

    return result;
}

void copy(const struct shape *src, struct shape *dest)
{
    dest->center = src->center;
    dest->shape_kind = dest->shape_kind;

    if (dest->shape_kind == RECTANGLE)
    {
        dest->u.rectangle.height = src->u.rectangle.height;
        dest->u.rectangle.width = src->u.rectangle.width;
    }
    else
    {
        dest->u.circle.radius = src->u.circle.radius;
    }
}