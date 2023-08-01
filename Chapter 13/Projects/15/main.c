/*
Modify Programming Project 6 from Chapter 10 so that it includes the following function:

int evaluate_RPN_expression(const char *expression);

The function returns the value of the RPN expression pointed to by expression.
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

#define ARRAY_LENGTH(array) (sizeof((array)) / sizeof((array)[0]))
#define STACK_SIZE 100
#define EXPRESSION_LENGTH 100

// external variables
char contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void stack_underflow(void);
void stack_overflow(void);
void push(int c);
int pop(void);
int evaluate_RPN_expression(const char *expression);

int main(void)
{
    char c;    
    char expression[EXPRESSION_LENGTH + 1];
    char *p = expression;

    printf("Enter an RPN expression: ");

    while ((c = getchar()) != EOF && c!= '\n' && p < expression + EXPRESSION_LENGTH)
    {
        *p = c;
        p++;
    }

    *p = '\0';

    printf("Value of expression: %d\n", evaluate_RPN_expression(expression));
    make_empty(); //if we are to rerun enter expression in a loop

    exit(EXIT_SUCCESS);
}

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

int evaluate_RPN_expression(const char *expression)
{
    const char operands[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    const char operators[] = {'+', '-', '*', '/', '='};
    int operand_1;
    int operand_2;
    char c;
    bool invalid_input;

    while(true)
    {
        sscanf(expression, "%c", &c);
        ++expression;
        while (*expression == ' ')
        {
            ++expression;
        }
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
                operand_1 = pop();
                operand_2 = pop();
                push(operand_1 + operand_2);
                break;
            }
            case '-':
            {
                operand_1 = pop();
                operand_2 = pop();
                push(operand_2 - operand_1);
                break;
            }
            case '*':
            {
                operand_1 = pop();
                operand_2 = pop();
                push(operand_1 * operand_2);
                break;
            }
            case '/':
            {
                operand_1 = pop();
                operand_2 = pop();
                push(operand_2 / operand_1);
                break;
            }
            case '=':
            {
                break;
            }
            default:
            {
                push(c - '0');                
                break;
            }
        }     
    }

    return pop();
}