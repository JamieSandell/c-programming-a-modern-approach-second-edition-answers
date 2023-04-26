/*

Which of the following would be valid prototypes for a function that returns
nothing and has one double parameter?

(a) void f(double x);
(b) void f(double);
(c) void f(x);
(d) f (double x);

Both (a) and (b) are valid prototypes. (c) isn't valid because it doesn't provide
the parameter x with a type. And (d) isn't valid because it doesn't specify the
return type of f (so it defaults to int when we require void).
*/