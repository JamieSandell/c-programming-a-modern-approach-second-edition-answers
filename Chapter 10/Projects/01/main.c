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

#define STACK_SIZE 100

/* external variables */
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

void push (char c)
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

char pop(void)
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

int main(void)
{
    char c;
    int braces = 0;
    int parentheses = 0;

    printf("Enter parentheses and/or braces: ");

    while((c = getchar()) != '\n')
    {
        switch (c)
        {
            case '(':
            {
                push(c);
                parentheses++;
                break;
            }
            case '{':
            {
                push(c);
                braces++;
                break;
            }
            case ')':
            {
                pop();
                parentheses--;
                break;
            }
            case '}':
            {
                pop();
                braces--;
                break;
            }
            default:
            {
                printf("Unhandled input\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    if (braces != 0 || parentheses != 0)
    {
        printf("Mismatched parentheses or braces.\n");
        exit(EXIT_FAILURE);
    }

    if (!is_empty())
    {
        printf("Stack is not empty.\n");
        EXIT_FAILURE;
    }

    printf("Parentheses/braces are nested properly.\n");

    exit(EXIT_SUCCESS);
}