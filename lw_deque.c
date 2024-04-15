// https://godbolt.org/z/GTzeorP7W

// double-ended queue
//      cons n          - инициализировать массив заданной длины
//      insert i v      - вставить элемент в произвольное место в массиве по индексу
//      push_front v    - добавить элемент в начало массива
//      pop_front       - удалить первый элемент массива
//      get v           - найти элемент с заданным значением в массиве
//      empty           - проверить отсутствие элементов в массиве
//      clear           - удалить все элементы из массива
//      erase_if p      - удалить значения из массива если условие предиката выполняется 

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
void*  find(void*, size_t);
void   push_front(void*, int);
void   pop_front(void*);
void   insert(void*, size_t, int);
void   erase(void*, size_t);

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
