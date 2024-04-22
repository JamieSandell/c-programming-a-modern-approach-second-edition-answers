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
        terminate("Error in create: new_stack failed\n");
    }
}

static void terminate(const char *message)
{
    printf("%s", message);
    exit(EXIT_FAILURE);
}