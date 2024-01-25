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

int main(void)
{
    return EXIT_SUCCESS;
}