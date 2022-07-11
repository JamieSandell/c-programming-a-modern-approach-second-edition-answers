/*
The following table shows telephone area codes in the state of Georgia along with the larg-
est city in each area:

Area Code   Major city
    229     Albany
    404     Atlanta
    470     Atlanta
    478     Macon
    678     Atlanta
    706     Columbus
    762     Columbus
    770     Atlanta
    912     Savannah

Write a switch statement whose controlling expression is the variable area_code. If the
value of area_code is in the table, the switch will print the corresponding
city name. Otherwise, the switch statement will display the message "Area code not
recognized". Use the techniques discussed in 5.3 to make the switch state-
ment as simple as possible.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int area_code = 770;

    switch (area_code)
    {
        case 229:
            printf("Albany");
            break;
        case 404: // fall through
        case 470: // fall through
        case 678: // fall through
        case 770:
            printf("Atlanta");
            break;
        case 706: // fall through
        case 762:
            printf("Columbus");
            break;
        case 478:
            printf("Macon");
            break;
        case 912:
            printf("Savannah");
            break;
        default:
            printf("Area code not recognized.");
            break;
    }
}