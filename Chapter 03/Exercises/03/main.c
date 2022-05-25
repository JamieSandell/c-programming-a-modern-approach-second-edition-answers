/*
For each of the following pairs of scanf format strings, indicate whether or not the two strings are equivalent. If they're not, show how they can be distinguished.

(a) "%d"       versus " %d"
(b) "%d-%d-%d" versus "%d -%d -%d"
(c) "%f"       versus "%f "
(d) "%f,%f"    versus "%f, %f"

(a) These are equivalent. The whitespace is ignored and then an integer scanned for.
(b) These are not equivalent. The one on the right would work if the input was in the format of the one on the left.
    It would match a number, skip none or more whitespace, match the - and so on and so forth.
    The one on the left would not work if the input was in the format of the one on the right.
    It would match a number and then attempt to match the whitespace with a -.
(c) These are equivalent. For the one on the left, if the input was like the one on the right it would
    match a float.
    For the one on the right, if the input was like the one on the left it would match a float and ignore none or more whitespace.
(d) These are not equivalent.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    return EXIT_SUCCESS;
}