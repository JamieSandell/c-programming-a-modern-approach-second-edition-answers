/*
Write the following functions. (The color structure is defined in Exercise 8.)

(a) struct color make_color(int red, int green, int blue);
Returns a color structure containing the specified red, green and blue values. If any argu-
ment is less than zero, the corresponding member of the structure will contain zero instead.
If any argument is greater than 255, the corresponding member of the structure will contain
255.

(b) int getRed(struct color c);
Returns the value of c's red member.

(c) bool equal_color(struct color color1, struct color color2);
Returns true if the corresponding members of color1 and color2 are equal.

(d) struct color brighter(struct color c);
Returns a color structure that represents a brighter version of the color c. The structure is
identical to c, except that each member has been divided by 0.7 (with the result truncated to
an integer). However, there are three special cases: (1) If all members of c are zero, the
function returns a color whose members all have the value 3. (2) If any member of c is
greater than 0 but less than 3, it is repaced by 3 before the division by 0.7. (3) If dividing by
0.7 causes a member to exceed 255, it is reduced to 255.

(e) struct color darker(struct color c);
Returns a color structure that represents a darker version of the color c. The structure is
identical to c, except that each member has been multiplies by 0.7 (with the result truncated
to an integer).
*/

#include <stdbool.h>
#include <stdlib.h>

#define MIN 0
#define MAX 255
#define DIVISOR 0.7
#define MULTIPLIER 0.7

struct color
{
    int red;
    int green;
    int blue;
};

struct color make_color(int red, int green, int blue);
int getRed(struct color c);
bool equal_color(struct color color1, struct color color2);
struct color brighter(struct color c);
struct color darker(struct color c);
int within_bounds(int color_part);

int main(void)
{
    return EXIT_SUCCESS;
}

int within_bounds(int color_part)
{
    if (color_part < MIN)
    {
        return 0;
    }
    else if (color_part > MAX)
    {
        return 255;
    }
    else
    {
        return color_part;
    }    
}

struct color make_color(int red, int green, int blue)
{
    red = within_bounds(red);
    green = within_bounds(green);
    blue = within_bounds(blue);

    struct color result = {.red = red, .green = green, .blue = blue};

    return result;
}

int getRed(struct color c)
{
    return c.red;
}

bool equal_color(struct color color1, struct color color2)
{
    if (color1.red == color2.red && color1.green == color2.green && color1.blue == color2.blue)
    {
        return true;
    }
    else
    {
        return false;
    }
}

struct color brighter(struct color c)
{
    if (c.red == 0 && c.green == 0 && c.blue == 0)
    {
        return c;
    }

    if (c.red < 3) // Assuming created via make_color, then no colour part will be less than 0, so only need to check < 3.
    {
        c.red = 3;
    }

    if (c.green < 3)
    {
        c.green = 3;
    }

    if (c.blue < 3)
    {
        c.blue = 3;
    }

    c.red /= DIVISOR;
    c.green /= DIVISOR;
    c.blue /= DIVISOR;

    c.red = within_bounds(c.red);
    c.green = within_bounds(c.green);
    c.blue = within_bounds(c.blue);

    return c;
}

struct color darker(struct color c)
{
    c.red *= MULTIPLIER;
    c.green *= MULTIPLIER;
    c.blue *= MULTIPLIER;
    
    return c;
}