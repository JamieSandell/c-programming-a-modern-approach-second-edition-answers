/*
(b) Redo the Stack type, this time using a linked-list representation instead of an array.
(Show both stack.h and stack.c)
*/

#include <stdlib.h>
#include <stdio.h>
#include "../stack.h"

struct node
{
    Item data;
    struct node *next;
};

struct stack_type
{
    int size;
    struct node *top;
};

static void terminate(const char *message);

Stack create(int size)
{
    Stack new_stack = malloc(sizeof(struct stack_type));

    if (new_stack == NULL)
    {
        terminate("Error in create: new_stack memory allocation failed.\n");
    }

    new_stack->size = size;
    new_stack->top = NULL;

    return new_stack;
}

void destroy(Stack stack)
{
    struct node *current = stack->top;
    struct node *temp;

    while (current != NULL)
    {
        temp = current->next;
        free(current);
        current = temp;
    }

    free(stack);
}

void push(Stack stack, Item item)
{
    struct node *new_node = malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        terminate("Error in push: failed to allocate memory for new_node.\n");
    }

    new_node->data = item;
    

    if (stack->top == NULL)
    {
        new_node->next = NULL;
        stack->top = new_node;
    }
    else
    {
        new_node->next = stack->top;
        stack->top = new_node;
    }
}

Item pop(Stack stack)
{
    if (is_empty(stack))
    {
        terminate("Error in pop: stack is empty\n");
    }

    Item item = stack->top->data;
    struct node *current = stack->top;
    stack->top = stack->top->next;
    free(current);
    return item;
}

bool is_empty(Stack stack)
{
    return stack->top == NULL;
}

static void terminate(const char *message)
{
    printf("%s", message);
    exit(EXIT_FAILURE);
}