// https://youtu.be/jAIFLEK3jiw
// https://www.youtube.com/watch?v=GZPqDvG615k

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} arraylist;

void init(arraylist* d, size_t n) {
    d->data = NULL;
    if (n) {
        d->data = calloc(n, sizeof(int));
        if (d->data == NULL) {
            d->capacity = 0;
            d->size = 0;
            return;
        }
    }
    d->capacity = n;
    d->size = 0;
}

void clear(arraylist* d) {
    free(d->data);
    d->data = NULL;
    d->capacity = 0;
    d->size = 0;
}

void push_back(arraylist* d, int value) {
    if (d == NULL) return;
    if (d->capacity <= d->size) {
        if (d->capacity == 0) d->capacity = 1;
        else d->capacity = d->capacity * 2;
        d->data = realloc(d->data, sizeof(int) * d->capacity);
        if (d->data == NULL) {
            d->capacity = 0;
            d->size = 0;
            return;
        }
    }
    d->data[d->size] = value;
    d->size = d->size + 1;
}

// test-driven development
void test_init() {
    arraylist a = {NULL, 0, 0};
    init(&a, 0);
    assert(a.capacity == 0);
    assert(a.size == 0);
    assert(a.data == NULL);
    
    init(&a, 10);
    assert(a.capacity == 10);
    assert(a.size == 0);
    assert(a.data != NULL);
}

void test_clear() {
    arraylist a = {0 ,0 ,0};
    init(&a, 100);
    assert(a.data != NULL);

    clear(&a);
    clear(&a);
    assert(a.capacity == 0);
    assert(a.size == 0);
    assert(a.data == NULL);

    init(&a, 0);
    clear(&a);
    assert(a.capacity == 0);
    assert(a.size == 0);
    assert(a.data == NULL);
}

void test_push_back() {
    push_back(NULL, 0);
    arraylist a;
    init(&a, 0);
    push_back(&a, 1);
    assert(a.data != NULL);
    assert(a.capacity == 1);
    assert(a.size == 1);
    assert(a.data[0] == 1);
    push_back(&a, 2);

}

int main(void) {
    
    test_init();
    test_clear();
    test_push_back();

}
