/*
Show what the following program will look like after preprocessing. Some lines of the pro-
gram may cause compilation errors; find all such errors.

#define N = 10
#define INC(x) x+1
#define SUB (x,y) x-y
#define SQR(x) ((x)*(x))
#define CUBE(x) (SQR(x)*(x))
#define M1(x,y) x##y
#define M2(x,y) #x #y

int main(void)
{
    int a[N], i, j, k, m;

#ifdef N
    i = j;
#else
    j = i;
#endif
    
    i = 10 * INC(j);
    i = SUB(j, k);
    i = SQR(SQR(j));
    i = CUBE(j);
    i = M1(j, k);
    puts(M2(i, j));
    
#undef SQR
    i = SQR(j);
#define SQR
    i = SQR(j);
    
    return 0;
}
*/

/*
int main(void)
{
    int a[= 10], i, j, k, l, m; // Error, array is given a size with an '='

    i = j; // Undefined behaviour, j isn't initialised.

    i = 10 * j + 1; // Undefined behaviour, j isn't initialised.
    i = (x, y) x - y(j, k); // Won't work as expected, should have wrapped each parameter in parentheses, so, #define SUB(x,y) (x)-(y)
    i = ((((j)*(j))*((j)*(j)))); // Undefined behaviour, j isn't initialised.
    i = (((j)*(j)) * (j)); // Undefined behaviour, j isn't initialised.
    i = jk; // Attempt to assign variable jk to i, jk has never been declared
    puts("i" "j");
    
    i = SQR(j); // Error has SQR was just undefined
    i = (j); // Legal as SQR was defined again, but wasn't defined with any tokens (missing ((x)*(x)) from the #define)

    return 0;
}
*/