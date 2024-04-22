#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "..\stack.h"

#define STACK_SIZE 5

int main(void)
{
    Stack stack = create(STACK_SIZE);
    Stack stack2 = create(STACK_SIZE);

    int a = 5;
    int b = 7;

    push(stack, a);
    printf("Pushed %d to stack 1.\n", a);
    push(stack2, b);
    printf("Pushed %d to stack 2.\n", b);
    int c = pop(stack);
    printf("Popped %d from stack 1.\n", c);
    push(stack2, c);
    printf("Pushed %d to stack 2.\n", c);

    while (is_empty(stack2) == false)
    {
        printf("Popped %d, from stack 2\n", pop(stack2));
    }

    if (is_empty(stack))
    {
        printf("Stack 1 is empty.\n");
    }

    if (is_empty(stack2) == false)
    {
        printf("Stack 2 is not empty.\n");
    }

    destroy(stack);
    destroy(stack2);

    return EXIT_SUCCESS;
}