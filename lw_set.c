#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int val_in_range(int lower, int upper) {
    return lower + (rand() % (upper - lower));
}

void   clear(void*);
bool   empty(void*);
bool   contains(void*, int);
void*  find(void*, int);
size_t size(void*);
size_t count(void*, int);
void   insert(void*, int);
void   erase(void*, int);

int main( void ) {
    void *a;

    insert(&a, 1);
    insert(&a, 1);
    insert(&a, 1);

    assert(contains(a, 1));
    assert(1 == count(a, 1));
    assert(NULL == find(a, 0));

    erase(&a, 1);

    assert(empty(a));
    assert(0 == size(a));

    clear(&a);

}
