#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int val_in_range(int lower, int upper) {
    return lower + (rand() % (upper - lower));
}

int *  cons(size_t n);
size_t size(void *);
void   clear(void *);
bool   empty(void *);
bool   eq(void *a, void *b);

// vector
void push_back(void *, int);
size_t get(void *a, size_t i);
void insert(void *a, size_t i, int v);
void erase(void *a, size_t i);
// stack
void pop(void *);
void push(void *, int);
int top(void *);
// double-ended queue
void push_front(void *, int);
void pop_front(void *);
void insert(void *a, size_t i, int v);
void erase(void *a, size_t i);
// queue
int front(void *);
int back(void *);
void pop(void *);
void push(void *, int);
// bonus
void erase_if(void *a, int v, bool (*p)(int));

int main( void ) {

    size_t n = val_in_range(1, 100);

    void *a = cons(n);
    
    clear(a);

    assert(empty(a));
}
