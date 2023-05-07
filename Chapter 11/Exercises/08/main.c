/*
Write the following function:

int *find_largest(int a[], int n);

When passed an array a of length n, the function will return a pointer to the array's largest
element.

int *find_largest(int a[], int n)
{
    for (int i = 1, int largest_index = 0; i < n; i++;)
    {
        if (a[largest_index] < a[i])
        {
            largest_index = i;
        }
    }

    return &a[largest_index];
}
*/