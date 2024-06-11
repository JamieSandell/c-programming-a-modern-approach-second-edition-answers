/*
(a) Write a "wrapper" function named try_math_fcn that calls a math function
(assumed to have a double argument and return a double value) and then checks
whether the call succedded. Here's how we might use try_math_fcn:

y = try_math_fcn(sqrt, x, "Error in call of sqrt");

If the call sqrt(x) is successful, try_math_fcn returns the value computed by sqrt.
If the call failed, try_math_fcn calls perror to print the message Error in call of
sqrt, then calls exit to terminate the program.

(b) Write a macro that has the same effect as try_math_fcn but builds the error mes-
sage from the function's name:

y = TRY_MATH_FCN(sqrt, x);

If the call of sqrt fails, the message will be Error in call of sqrt. Hint: Have
TRY_MATH_FCN call try_math_fcn.
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define TRY_MATH_FCN(f, x) (try_math_fcn((f), (x), "Error in call of " #f))

double try_math_fcn(double (*fcn)(double), double x, const char *error_message);

int main(void)
{
    return EXIT_SUCCESS;
}

double try_math_fcn(double (*fcn)(double), double x, const char *error_message)
{
    errno = 0;
    double result = (*fcn)(x);

    if (errno)
    {
        perror(error_message);
        exit(EXIT_FAILURE);
    }

    return result;
}