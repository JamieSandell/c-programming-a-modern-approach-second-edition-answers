/*
The following program outline shows only function definitions and variable declarations.

int a;

void f(int b)
{
    int c;
}

void g(void)
{
    int d;
    {
        int e;
    }
}

int main(void)
{
    int f;
}
For each of the following scopes, list all variable and parameter names visible in that scope:

(a) The f function
(b) The g function
(c) The block in which e is declared
(d) The main function

(a) a is an extern. b is a parameter. c is a local variable.
(b) a is an extern. d is a local variable. e is a block variable within g.
(c) a is an extern, d is a local variable. e is declared within a block within g.
(d) a is an extern. f is a loca variable.
*/