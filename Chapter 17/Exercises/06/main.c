/*
Modify the delete_from_list function so that it only uses one pointer variable instead
of two (cur and prev).
*/

#include <stdlib.h>

struct node
{
    int value; // data stored in the node
    struct node *next; // pointer to the next node
};

// Delete the first node using n
struct node *delete_from_list(struct node *list, int n);
struct node *delete_from_list_single(struct node **list, int n);

int main(void)
{

    return EXIT_SUCCESS;
}

struct node *delete_from_list_single(struct node *list, int n)
{
    struct node **pcur;

    for (pcur = &list; *pcur != NULL && (*pcur)->value != n; pcur = &(*pcur)->next)
    {
        ;
    }

    if (*pcur != NULL)
    {
        struct node *cur = *pcur;
        *pcur = (*pcur)->next;
        free(cur);
    }

    return list;
}

struct node *delete_from_list(struct node *list, int n)
{
    struct node *cur;
    struct node *prev;

    for
    (
        cur = list, prev = NULL;
        cur != NULL && cur->value != n;
        prev = cur, cur = cur->next
    )
    {
        ;
    }

    if (cur == NULL)
    {
        return list; // n was not found
    }

    if (prev == NULL)
    {
        list = list->next; // n is in the first node
    }
    else
    {
        prev->next = cur->next; // n is in some other node
    }

    free(cur);

    return list;
}