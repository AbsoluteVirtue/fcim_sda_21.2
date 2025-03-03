// https://godbolt.org/z/9n9nnq1xv
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 9

typedef struct
{
    int *data;
    size_t size;
    size_t capacity;
} arraylist;

void init(arraylist *d, size_t n)
{
    d->data = NULL;
    if (n)
    {
        d->data = calloc(n, sizeof(int));
        if (d->data == NULL)
        {
            d->capacity = 0;
            d->size = 0;
            return;
        }
    }
    d->capacity = n;
    d->size = 0;
}

void clear(arraylist *d)
{
    free(d->data);
    d->data = NULL;
    d->capacity = 0;
    d->size = 0;
}

void push_back(arraylist *d, int value)
{
    if (d == NULL)
        return;
    if (d->capacity <= d->size)
    {
        if (d->capacity == 0)
            d->capacity = 1;
        else
            d->capacity = d->capacity * 2;
        int *tmp = d->data;
        d->data = realloc(d->data, sizeof(int) * d->capacity);
        if (d->data == NULL)
        {
            free(tmp);
            d->capacity = 0;
            d->size = 0;
            return;
        }
    }
    d->data[d->size] = value;
    d->size = d->size + 1;
}

void pop_back(arraylist *d)
{
    if (d->size)
        d->size--;
}

size_t size(arraylist d)
{
    return d.size;
}

int at(arraylist d, size_t index)
{
    if (d.size && index < d.size)
    {
        return d.data[index];
    }
    return 0;
}

int main(void)
{
    bool adj[N][N] = {
        {0, 1, 0, 0, 0, 0, 0, 1, 0},
        {1, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 1, 0},
        {1, 1, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0},
    };

    bool list[N] = {0};

    arraylist stack;
    init(&stack, N);

    push_back(&stack, 0);
    list[0] = 1;

    while (size(stack) != 0)
    {
        int top = at(stack, size(stack) - 1);
        
        bool discovered = true;
        for (size_t i = 0; i < N; i++)
        {
            if (adj[top][i] == true && list[i] == false)
            {
                push_back(&stack, i);
                list[i] = true;
                discovered = false;
                printf("%zu ", i);
                break;
            }
        }
        if (discovered) pop_back(&stack);
    }
}

// 0 1 2 3 6 4 5 7 8
