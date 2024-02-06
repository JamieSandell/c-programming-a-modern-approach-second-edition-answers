/*
Modify the print_part function of Section 16.2 so that its parameter is a pointer to a
part structure. Use the -> operator in your answer.
*/

#include <stdlib.h>

#define NAME_LEN 50

struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

void print_part(const struct part *part)
{
    printf("Part number: %d\n", part->number);
    printf("Part name: %s\n", part->name);
    printf("Quantity on hand: %d\n", part->on_hand);
}

int main(void)
{
    return EXIT_SUCCESS;
}