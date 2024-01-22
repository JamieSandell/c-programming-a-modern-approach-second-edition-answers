#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

// external variables
char contents[STACK_SIZE];
int top = 0;

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void stack_underflow()
{
    printf("Stack underflow.\n");
    exit(EXIT_FAILURE);
}

void stack_overflow()
{
    printf("Stack overflow.\n");
    exit(EXIT_FAILURE);
}

void push (int c)
{
    if (is_full())
    {
        stack_overflow();
    }
    else
    {
        contents[top++] = c;
    }
}

int pop(void)
{
    if (is_empty())
    {
        stack_underflow();
        exit(EXIT_FAILURE);
    }
    else
    {
        return contents[--top];
    }
}