/*
The following program outline shows only function definitions and variable declarations.

int b, c;

void f(void)
{
    int b, d;
}

void g(int a)
{
    int c;
    {
        int a, d;
    }
}

int main(void)
{
    int c, d;
}

For each of the following scopes, list all variable and parameter names visible in that scope.
If there's more than one variable or parameter with the same name, indicate which one is visible.

(a) The f function
(b) The g function
(c) The block in which a and d are declared
(d) The main function

(a) c (extern), b is local (overrides the extern of b), and d (is local).
(b) b (extern), c is local (overrides the extern of c), and d (only within it's block within g).
(c) b and c (extern) and a and d (local block within g).
(d) b (extern), c (overrides extern c) and d (local).
*/