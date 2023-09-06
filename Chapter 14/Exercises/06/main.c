/*
(a) Write a macro DISP(f,x) that expands into a call to printf that displays the value
of the function f when called with argument x. For example,

DISP(sqrt, 3.0);

should expand into

printf("sqrt(%g) = %g\n", 3.0, sqrt(3.0));

(b) Write a macro DISP2(f,x,y) that's similar to DISP but works for functions with
two arguments.

(a)
DISP(f,x) (printf("%s(%g) = %g\n", (#f), (x), (f(x))))

(b)
DISP2(f,x,y) (printf("%s(%g, %g) = %g\n", (#f), (x), (y), (f((x), (y)))))
*/