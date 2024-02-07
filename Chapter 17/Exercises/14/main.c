/*
Modify the delete_from_list function (17.5) so that its first parameter has
type struct node ** (a pointer to a pointer to the first node in a list) and its return type is
void. delete_from_list must modify its first argument to point to the list after the
desired node has been deleted.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value; // data stored in the node
    struct node *next; // pointer to the next node
};

// Delete the first node using n
void delete_from_list(struct node **list, int n);

int main(void)
{
    return EXIT_SUCCESS;
}

void delete_from_list(struct node **list, int n)
{
    if (*list == NULL)
    {
        printf("Error: List is empty.\n");
        return;
    }

    struct node *node;

    for (node = *list; node != NULL && node->value != n; list = &(node->next), node = node->next)
    {
        ;
    }

    if (node->value == n)
    {
        *list = node->next;
        free(node);
    }
}
