/*
We discussed using the expression sizeof(a) / sizeof(a[0]) to calculate the num-
ber of elements in an array. The expression sizeof(a) / sizeof(t), where t is the type
of a's elements, would also work, but it's considered an inferior technique. Why?

If the type of the array changed you'd have to update it in sizeof(t).
On top of that, if you created a macro for this, it'd only work on one type of array.
*/