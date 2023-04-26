/*
The following function, which computes the area of a triangle, contains two errors. Locate
the errors and show how to fix them. (Hint: There are no errors in the formula.)

double triangle_area(double base, height)
double product;
{
    product = base * height;
    return product / 2;
}

Height is missing the type and the declaration of product should be inside the function
body.

double triangle_area(double base, double height)
{
    double product;
    product = base * height;
    return product / 2;
}
*/