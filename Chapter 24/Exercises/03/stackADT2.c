/*
Modify the stackADT2.c file of Section 19.4 so that it uses an assert to test for errors
instead of using if statements (Note that the terminate function is no longer necessary
and can be removed).
*/

/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* stackADT2.c (Chapter 19, page 498) */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stackADT2.h"

struct stack_type {
  Item *contents;
  int top;
  int size;
};

Stack create(int size)
{
  Stack s = malloc(sizeof(struct stack_type));
  assert (s != NULL);
  s->contents = malloc(size * sizeof(Item));
  if (s->contents == NULL) {
    free(s);
    fprintf(stderr, "Error in create: stack could not be created.");
    exit(EXIT_FAILURE);
  }
  s->top = 0;
  s->size = size;
  return s;
}

void destroy(Stack s)
{
  free(s->contents);
  free(s);
}

void make_empty(Stack s)
{
  s->top = 0;
}

bool is_empty(Stack s)
{
  return s->top == 0;
}

bool is_full(Stack s)
{
  return s->top == s->size;
}

void push(Stack s, Item i)
{
  assert(!is_full(s));
  s->contents[s->top++] = i;
}

Item pop(Stack s)
{
  assert(!is_empty(s));
  return s->contents[--s->top];
}
