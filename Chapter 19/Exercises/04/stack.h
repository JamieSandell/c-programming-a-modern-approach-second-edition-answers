#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct stack_type *Stack;
typedef int Item;

Stack create(int size);
void destroy(Stack stack);
void push(Stack stack, Item item);
Item pop(Stack stack);
bool is_empty(Stack stack);

#endif