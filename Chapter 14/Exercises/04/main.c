/*
For each of the following macros, give an example that illustrates a problem with the macro
and show how to fix it.

(a) #define AVG(x,y)    (x-y)/2
(b) #define AREA(x,y)   (x)*(y)

(a) AVG(1+1, 2+2), the itention would have been AVG(2, 4), which would equate to -2 / 2 = -1,
however AVG(1+1, 2+2) gives (1+1 - 2+2)/2 which is 2 / 2

#define AVG(x,y)        (((x)-(y))/2)

(b) sum = 5 / AREA(2,5) equates to sum = 5 / (2) * (5), equates to 10

#define AREA(x,y)       ((x) * (y))
*/
