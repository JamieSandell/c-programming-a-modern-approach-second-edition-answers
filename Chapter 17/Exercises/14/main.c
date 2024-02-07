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
void *my_malloc(size_t size);
void print_list(const struct node *list);

int main(void)
{
    struct node *a = my_malloc(sizeof(*a));
    struct node *b = my_malloc(sizeof(*b));
    struct node *c = my_malloc(sizeof(*c));

    a->value = 1;
    a->next = b;
    b->value = 10;
    b->next = c;
    c->value = 20;
    c->next = NULL;

    print_list(a);

    struct node **list = &a;
    delete_from_list(list, 10);
    print_list(a);
    delete_from_list(list, 1);
    print_list(a);
    delete_from_list(list, 20);
    print_list(a);

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

void *my_malloc(size_t size)
{
    void *result = malloc(size);

    if (result == NULL)
    {
        printf("Error! Couldn't allocate memory\n");
        exit(EXIT_FAILURE);
    }

    return result;
}

void print_list(const struct node *list)
{
    for (const struct node *node = list; node != NULL; node = node->next)
    {
        printf("%d\n", node->value);
    }
}
