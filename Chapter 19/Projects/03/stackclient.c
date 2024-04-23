/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* stackclient.c (Chapter 19, page 494) */

#include <stdio.h>
#include "stackADT.h"

int main(void)
{
  Stack s1, s2;
  int n;

  s1 = create();
  s2 = create();

  push(s1, 1);
  printf("Length of stack 1: %d\n", length(s1));
  push(s1, 2);
  printf("Length of stack 1: %d\n", length(s1));

  n = pop(s1);
  printf("Popped %d from s1\n", n);
  printf("Length of stack 1: %d\n", length(s1));
  push(s2, n);
  printf("Length of stack 2: %d\n", length(s2));
  n = pop(s1);
  printf("Length of stack 1: %d\n", length(s1));
  printf("Popped %d from s1\n", n);
  push(s2, n);
  printf("Length of stack 2: %d\n", length(s2));

  destroy(s1);

  while (!is_empty(s2))
  {
    printf("Popped %d from s2\n", pop(s2));
    printf("Length of stack 2: %d\n", length(s2));
  }

  push(s2, 3);
  printf("Length of stack 2: %d\n", length(s2));
  make_empty(s2);
  printf("Length of stack 2: %d\n", length(s2));
  if (is_empty(s2))
    printf("s2 is empty\n");
  else
    printf("s2 is not empty\n");

  destroy(s2);

  return 0;
}
