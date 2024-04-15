// https://godbolt.org/z/1qxqMsPrr

// queue
//      cons n          - инициализировать массив заданной длины
//      front           - найти первый элемент в массиве
//      back            - найти последний элемент в массиве
//      push v          - добавить элемент в конец массива
//      pop             - удалить первый элемент массива
//      empty           - проверить отсутствие элементов в массиве
//      size            - определить длину массива
//      clear           - удалить все элементы из массива

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
