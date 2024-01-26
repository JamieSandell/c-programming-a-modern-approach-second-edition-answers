/*
(a) Declare a tag for an enumerataion whose values represent the seven days of the week.
(b) Use typedef to define a name for the enumeration of part (a).
*/

#include <stdlib.h>

/*enum day // (a)
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} day_of_week;*/

typedef enum day // (b)
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} day;

int main(void)
{
    day today = FRIDAY;

    return EXIT_SUCCESS;
}