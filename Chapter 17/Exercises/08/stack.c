/*
Section 15.2 describes a file, stack.c, that provides functions for storing integers in a
stack. In that section, the stack was implemented as an array. Modify stack.c so that a
stack is now stored as a linked list. Replace the contents and top variables by a single
variable that points to the first node in the list (the "top" of the stack). Write the functions in
stack.c so that they use this pointer. Remove the is_full function, instead having
push return either true (if memory was available to create a node) or false (if not).
*/

#include <stdbool.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct node *top = NULL;

void make_empty(void);
int pop(void);
bool push(int n);

int main(void)
{
    return EXIT_SUCCESS;
}

void make_empty(void)
{
    struct node *p;
    struct node *temp;

    for (p = top; p != NULL; p = p->next)
    {
        temp = p;
        p = p->next;
        free(temp);
    }
}

int pop(void)
{
    if (top == NULL)
    {
        printf("Error: empty stack.\n");
        exit(EXIT_FAILURE);
    }

    struct Node *temp = top;
    int temp_data = top->value;
    top = top->next;
    free(temp);

    return temp_data;
}

bool push(int n)
{
    struct node *p = malloc(sizeof(*p));

    if (p == NULL)
    {
        return false;
    }

    top->next = p;
    p->next = NULL;
    p->value = n;

    return true;
}