/*
Modify the compare_parts function so that parts are sorted with their numbers in
descending order.
*/

#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define NAME_LEN 50

struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

struct part inventory[MAX_SIZE];
int number_of_parts = 0;

void add_part(const struct part *part);
int compare_parts(const void *a, const void *b);

int main(void)
{
    struct part a = {.number = 10, .name = "Part A", .on_hand = 20};
    struct part b = {.number = 5, .name = "Part B", .on_hand = 10};
    struct part c = {.number = 100, .name = "Part C", .on_hand = 50};

    add_part(&a);
    add_part(&b);
    add_part(&c);

    qsort(inventory, number_of_parts, sizeof(struct part), &compare_parts);

    return EXIT_SUCCESS;
}

void add_part(const struct part *part)
{
    inventory[number_of_parts].number = part->number;
    strcpy(inventory[number_of_parts].name, part->name);
    inventory[number_of_parts].on_hand = part->on_hand;
    number_of_parts++;
}

int compare_parts(const void *a, const void *b)
{
    const struct part *c = (const struct part *)a;
    const struct part *d = (const struct part *)b;

    if (c->number == d->number)
    {
        return 0;
    }
    else if(c->number > d->number)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}