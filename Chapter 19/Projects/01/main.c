/*
Modify Programming Project 1 from Chapter 10 so that it uses the stack ADT described in
Section 19.4. You may use any of the implementations of the ADT described in that section.
*/

/*
Modify the stack example of Section 10.2 so that it stores characters instead of integers.
Next, add a main function that asks the user to enter a series of parentheses and/or braces,
then indicates whether or not they're properly nested:

Enter parentheses and/or braces: ((){}{()})
Parentheses/braces are nested properly

Hint: As the program reads characters, have it push each left parenthesis or left brace. When
it reads a right parenthesis or brace, have it pop the stack and check that the item popped is a
matching parenthesis or brace. (If not, the parentheses/braces aren't nested properly.) When
the program reads the new-line character, have it check whether the stack is empty; if so, the
parentheses/braces are matched. If the stack isn't empty (or if stack_underflow is ever
called), the parentheses/braces aren't matched. If stack_overflow is called, have the
program print the message Stack overflow and terminate immediately.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stackADT2.h"

#define STACK_SIZE 100

int main(void)
{
    char c;
    int braces = 0;
    int parentheses = 0;
    Stack stack = create(STACK_SIZE);

    printf("Enter parentheses and/or braces: ");

    while((c = getchar()) != '\n')
    {
        switch (c)
        {
            case '(':
            {
                push(stack, c);
                parentheses++;
                break;
            }
            case '{':
            {
                push(stack, c);
                braces++;
                break;
            }
            case ')':
            {
                pop(stack);
                parentheses--;
                break;
            }
            case '}':
            {
                pop(stack);
                braces--;
                break;
            }
            default:
            {
                printf("Unhandled input\n");
                destroy(stack);
                exit(EXIT_FAILURE);
            }
        }
    }

    if (braces != 0 || parentheses != 0)
    {
        printf("Mismatched parentheses or braces.\n");
        destroy(stack);
        exit(EXIT_FAILURE);
    }

    if (!is_empty(stack))
    {
        printf("Stack is not empty.\n");
        destroy(stack);
        EXIT_FAILURE;
    }

    printf("Parentheses/braces are nested properly.\n");
    destroy(stack);
    exit(EXIT_SUCCESS);
}