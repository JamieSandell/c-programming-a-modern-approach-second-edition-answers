/*
Suppose that the function f has the following definition:
int f(int a, int b) { ... }

which of the following statements are legal? (Assume that i has type int
and x has type double.)

(a) i = f(83, 12);
(b) x = f(83, 12);
(c) i = f(3.15, 9.28);
(d) x = f(3.15, 9.28);
(e) f(83, 12);

(a): Legal and normal behaviour.
(b): Legal and assigns int result to double.
(c): Legal, but loses decimal values as f's parameters are converted to int.
(d): Legal, but loses decimal values as f's parameters are converted to int.
(e): legal, but doesn't do anything with returned value.
*/