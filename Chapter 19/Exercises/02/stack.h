/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* stack.h (Chapter 19, page 488) */

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>   /* C99 only */

#define PRIVATE static
#define PUBLIC

PRIVATE void make_empty(void);
PRIVATE bool is_empty(void);
PRIVATE bool is_full(void);
PRIVATE void push(int i);
PRIVATE int pop(void);

#endif