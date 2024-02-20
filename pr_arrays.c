#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct data {
    void *p;
    size_t size;
    size_t capacity;
};

typedef struct data* array;

array cons(size_t);
size_t size(array);
bool empty(array);
void clear(array);

#define at(a, i) ((int*)a->p)[i]

int main(void) {
    array a = cons(5);

    for (size_t i = 0; i < size(a); i++) {
        at(a, i) = i + 1;
        printf("%d ", at(a, i));
    }

    array b = cons(size(a));

    for (size_t i = 0; i < size(b); i++) {
        at(b, i) = at(a, i);
        printf("%d ", at(b, i));
    }

    clear(a); clear(b);

    assert(empty(a));

    for (size_t i = 0; i < size(b); i++) {
        printf("%d ", at(b, i));
    }

    free(a); free(b);
}

array cons(size_t n) {
    array r = malloc(sizeof(struct data));
    r->p = calloc(n, sizeof(int));
    r->size = r->capacity = n;
    return r;
}

size_t size(array a) {
    return a->size;
}

bool empty(array a) {
    return !size(a);
}

void clear(array a) {
    free(a->p);
    a->p = NULL;
    a->size = a->capacity = 0;
}
