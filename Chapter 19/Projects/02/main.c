/*
Modify Programming Project 6 from Chapter 10 so that it uses the stack ADT described in
Section 19.4. You may use any of the implementations of the ADT described in that section.
*/

/*
Some calculators (notably those from Hewlett-Packard) use a system of writing mathemati-
cal expressions known as Reverse Polish Notation (RPN). In this notation, operators are
placed after their operands instead of between their operands. For example, 1 + 2 would be
written 1 2 + in RPN, and 1 + 2 * 3 would be written 1 2 3 * +. RPN expressions can easily
be evaluated using a stack. The algorithm involves reading the operators and operands in an
expression from left to right, performing the following actions:

    When an operand is encountered, push it onto the stack.
    When an operator is encountered, pop its operands from the stack, perform the opera-
    tion on those operands and then push the result onto the stack.

Write a program that evaluates RPN expressions. The operands will be single-digit integers.
The operators are +, -, *, /, and =. The = operator causes the top stack item to be displayed;
afterwards, the stack is cleared and the user is prompted to enter another expression. The
process continues until the user enters a character that is not an operator or operand:

Enter an RPN expression: 1 2 3 * + =
Value of expression: 7
Enter an RPN expression: 5 8 * 4 9 - / =
Value of expression: -8
Enter an RPN expression: q

If the stack overflows, the program will display the message Expression is too com-
plex and terminate. If the stack underflows (because of an expression such as 1 2 + +), the
program will display the message Not enough operands in expression and termi-
nate. Hints: Incorporate the stack code from Section 10.2 into your program. Use
scanf(" %c", &ch) to read the operators and operands.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stackADT2.h"

#define ARRAY_LENGTH(array) (sizeof((array)) / sizeof((array)[0]))
#define STACK_SIZE 100

int main(void)
{
    char c;
    const char operands[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    const char operators[] = {'+', '-', '*', '/', '='};
    bool invalid_input;
    int operand_1;
    int operand_2;
    Stack stack = create(STACK_SIZE);

    printf("Enter an RPN expression: ");

    while(true)
    {
        scanf(" %c", &c);
        invalid_input = true;

        for (int i = 0; i < ARRAY_LENGTH(operands); i++)
        {
            if (c == operands[i])
            {
                invalid_input = false;
                break;
            }
        }

        if (invalid_input)
        {
            for (int i = 0; i < ARRAY_LENGTH(operators); i++)
            {
                if (c == operators[i])
                {
                    invalid_input = false;
                    break;
                }
            }
        }        

        if (invalid_input)
        {
            break;
        }

        switch (c)
        {
            case '+':
            {
                operand_1 = pop(stack);
                operand_2 = pop(stack);
                push(operand_1 + operand_2);
                break;
            }
            case '-':
            {
                operand_1 = pop(stack);
                operand_2 = pop(stack);
                push(stack, operand_2 - operand_1);
                break;
            }
            case '*':
            {
                operand_1 = pop(stack);
                operand_2 = pop(stack);
                push(stack, operand_1 * operand_2);
                break;
            }
            case '/':
            {
                operand_1 = pop(stack);
                operand_2 = pop(stack);
                push(stack, operand_2 / operand_1);
                break;
            }
            case '=':
            {
                printf("Value of expression: %d\n", pop(stack));
                make_empty(stack);
                printf("Enter an RPN expression: ");
                break;
            }
            default:
            {
                push(stack, c - '0');                
                break;
            }
        }     
    }

    destroy(stack);
    exit(EXIT_SUCCESS);
}