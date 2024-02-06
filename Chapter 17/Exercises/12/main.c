/*
Write the following function:

struct node *find_last(struct node *list, int n);

The list parameter points to a linked list. The function should return a pointer to the last
node that contains n; it should return NULL if n doesn't appear in the list. Assume that the
node structure is the one defined in Section 17.5.
*/

#include <stdlib.h>

#define NAME_LEN 50

struct node
{
    int data;
    struct node *next;
};

struct node *find_last(struct node *list, int n);

int main(void)
{
    return EXIT_SUCCESS;
}

struct node *find_last(struct node *list, int n)
{
    struct node *result = NULL;
    
    for (struct node *p = list; p != NULL; p = p->next)
    {
        if (p->data == n)
        {
            result = p;
        }
    }

    return result;
}