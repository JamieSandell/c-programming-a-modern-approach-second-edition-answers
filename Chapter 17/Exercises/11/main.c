/*
Write the following function:

int count_occurrences(struct node *list, int n);

The list parameter points to a linked list; the function should return the number of times
that n appears in this list. Assume that the node structure is the one defined in Section 17.5.
*/

#include <stdlib.h>

#define NAME_LEN 50

struct node
{
    int data;
    struct node *next;
};

int count_occurrences(const struct node *list, int n);

int main(void)
{
    return EXIT_SUCCESS;
}

int count_occurrences(const struct node *list, int n)
{
    int count = 0;

    for (const struct node *p = list; p != NULL; p = p->next)
    {
        if (p->data == n)
        {
            ++count;
        }
    }

    return count;
}