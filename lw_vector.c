// https://godbolt.org/z/PsxceYx65

// vector
//      cons n          - инициализировать массив заданной длины
//      erase i         - удалить произвольный элемент массива по индексу
//      insert i v      - вставить элемент в произвольное место в массиве по индексу
//      push_back v     - добавить элемент в конец массива
//      get v           - найти элемент с заданным значением в массиве
//      size            - определить длину массива
//      clear           - удалить все элементы из массива
//      eq a b          - сравнить два массива
//      erase_if v p    - удалить значение из массива если условие предиката выполняется 

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
void   push_back(void*, int);
void   insert(void*, size_t, int);
void   erase(void*, size_t);

int main( void ) {

    size_t n = val_in_range(1, 100);

    void *a = cons(n);

    for (size_t i = 0; i < size(a); i++) { printf("%d ", get(a, i)); } printf("\n");

    clear(a);

    for (size_t i = 0; i < 5; i++) {
        push_back(a, val_in_range(-10, 10));
    }

    for (size_t i = 0; i < size(a); i++) { printf("%d ", get(a, i)); } printf("\n");

    insert(a, val_in_range(0, n - 1), 0);

    for (size_t i = 0; i < size(a); i++) { printf("%d ", get(a, i)); } printf("\n");

    erase(a, val_in_range(0, n - 1));

    for (size_t i = 0; i < size(a); i++) { printf("%d ", get(a, i)); }

}
