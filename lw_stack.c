// https://godbolt.org/z/bTGsPMhcW

// stack
//      cons n          - инициализировать массив заданной длины
//      pop             - удалить последний добавленный элемент массива
//      push v          - добавить элемент в массив за последним добавленным
//      top             - найти последний добавленный элемент массива
//      size            - определить длину массива
//      empty           - проверить наличие элементов в массиве
//      eq a b          - сравнить два массива

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
void   pop(void*);
void   push(void*, int);
int    top(void*);

int main( void ) {

    size_t n = val_in_range(1, 100);

    void *a = cons(n);

    clear(a);

    for (size_t i = 0; i < 5; i++) {
        push(a, val_in_range(-10, 10));
    }

    for ( ; !empty(a); pop(a)) { printf("%d ", top(a)); }

}
