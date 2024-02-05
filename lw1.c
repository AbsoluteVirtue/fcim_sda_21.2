#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int val_in_range(int lower, int upper)
{
    return lower + (rand() % (upper - lower));
}

int *cons(size_t n);
size_t size(int *);
void insert(int *a, size_t i, int v);
void erase(int *a, size_t i);
void clear(int *);

int main( void )
{
    size_t n = val_in_range(1, 100);
    int *a = cons(n);

    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    
    insert(a, val_in_range(0, n - 1), 0);

    for (size_t i = 0; i < size(a); i++)
    {
        printf("%d ", a[i]);
    }

    erase(a, val_in_range(0, n - 1));

    clear(a);

    for (size_t i = 0; i < size(a); i++)
    {
        printf("%d ", a[i]);
    }
}
