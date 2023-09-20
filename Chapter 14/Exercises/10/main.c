/*
Functions can often -- but not always -- be written as parameterized macros. Discuss what
characteristics of a function would make it unsuitable as a macro.

Functions that may often be passed arguments with side effects of assignment, such as the
arguments supplied with the prefix and postfix operators shouldn't be used in a macro

We can see from question 5 how this can cause unexpected behavior because the macro is passed
a value with a postfix increment operator, and is then replaced multiple times in a ternary
operation by the preprocessor. This caused the value i to be incremented by different amounts
depending on how much of the condition was checked, and whether the condition evaluated to false.

A function wouldn't have this problem because passing a value of ++i would create a copy of what
that expression evaluates to, and then provide it to the function.
*/