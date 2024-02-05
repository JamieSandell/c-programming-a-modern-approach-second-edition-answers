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

struct stack
{
    int value;
    struct stack *next;
} top;

void make_empty(void);
int pop(void);
bool push(int n);

int main(void)
{
    top.next = NULL;

    return EXIT_SUCCESS;
}

bool push(int n)
{
    struct stack *p = malloc(sizeof(*p));

    if (p == NULL)
    {
        return false;
    }

    top.value = n;
    top.next = p;
    top = p;

    return true;
}