/*
Suppose that high, low and middle are all pointer variables of the same type, and that
low and high point to elements of an array. Why is the following statement illegal, and
how could it be fixed?

middle = (low + high) / 2;

The only arithemtic you can do on a pointer is subtraction.
Pointers contain addresses. Adding two addresses makes no sense, because you have no idea what you would point to.
Subtracting two addresses lets you compute the offset between these two addresses, which may be very useful in some situations.

So you could do:

middle = (high - low) / 2 + low;

or

*middle = (*low) + (*high) / 2;
*/