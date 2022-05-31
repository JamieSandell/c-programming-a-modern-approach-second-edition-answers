/*
If i and j are positive integers, does (-i)/j always have the same value as -(i/j)?
Justify your answer.

Yes it does for C99 as division of negative operands applies round-towards-zero.
In C89 it is implementation defined.

C89 allows (-1) / 2 == -1, while C99 requires (-1) / 2 == 0
*/