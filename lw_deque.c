#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int val_in_range(int lower, int upper) {
    return lower + (rand() % (upper - lower));
}

int *  cons(size_t n);
void   clear(void *);
bool   empty(void *);
bool   eq(void *a, void *b);
size_t size(void *);
size_t get(void *, size_t);
void   push_front(void *, int);
void   pop_front(void *);
void   insert(void *a, size_t i, int v);
void   erase(void *a, size_t i);

int main( void ) {

    size_t n = val_in_range(1, 100);

    void *a = cons(n);

    for (size_t i = 0; i < size(a); i++) { printf("%d ", get(a, i)); } printf("\n");

    clear(a);

    for (size_t i = 0; i < 5; i++) {
        push_front(a, val_in_range(-10, 10));
    }

    for ( ; !empty(a); pop_front(a)) { printf("%d ", get(a, 0)); }

}