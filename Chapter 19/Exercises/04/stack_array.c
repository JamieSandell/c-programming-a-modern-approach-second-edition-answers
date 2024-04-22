/*
(a) Write an implementation of the Stack type, assuming that Stack is a structure con-
taining a fixed-length array.
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static void terminate(const char *message);

struct stack_type
{
    Item *contents;
    int size;
    int count;
};

Stack create(int size)
{
    Stack new_stack = malloc(sizeof(struct stack_type));

    if (new_stack == NULL)
    {
        terminate("Error in create: new_stack failed memory allocation.\n");
    }

    new_stack->contents = malloc(sizeof(Item) * size);

    if (new_stack->contents == NULL)
    {
        terminate("Error in create: new_stack->contents failed memory allocation.\n");
    }

    new_stack->size = size;
    new_stack->count = 0;

    return new_stack;
}

void destroy(Stack stack)
{
    free(stack->contents);
    free(stack);
}

void push(Stack stack, Item item)
{
    if (stack->count >= stack->size)
    {
        terminate("Error in push: overflow, stack size exceeded.\n");
    }

    stack->contents[stack->count++] = item;
}

static void terminate(const char *message)
{
    printf("%s", message);
    exit(EXIT_FAILURE);
}