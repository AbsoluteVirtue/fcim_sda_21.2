#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int val_in_range(int lower, int upper) {
    return lower + (rand() % (upper - lower));
}

void*  cons(size_t);
void   clear(void*);
bool   empty(void*);
bool   eq(void*, void*);
size_t size(void*);
int    front(void*);
int    back(void*);
void   pop(void*);
void   push(void*, int);

int main( void ) {

    size_t n = val_in_range(1, 100);

    void *a = cons(n);

    clear(a);

    for (size_t i = 0; i < 5; i++) {
        push(a, val_in_range(-10, 10));
    }

    for ( ; !empty(a); pop(a)) { printf("%d ", front(a)); }
}
