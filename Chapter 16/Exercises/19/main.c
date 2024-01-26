/*
Declare a structure with the following members whose tag is pinball_machine:

name -- a string of up to 40 characters
year -- an integer (representing the year of manufacture)
type -- an enumeration with the values EM (electromechanical) and SS (solid state)
players -- an integer (representing the maximum number of players)
*/

#include <stdlib.h>

int main(void)
{
    enum type
    {
        EM,
        SS
    };

    struct pinball_machine
    {
        char name[40];
        int year;
        enum type type;
        int players;
    };

    return EXIT_SUCCESS;
}