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

#include <cassert>
#include <cstdio>
#include <queue>

using dynarray = std::queue<int>;

int main() {
    dynarray a = {};

    a.push(10);
    a.push(20);
    a.push(30);

    dynarray b = a;

    assert(a == b);

    for ( ; !a.empty(); a.pop()) printf("%d ", a.front());

    assert(a.empty());

    assert(3 == b.size());

    for ( ; !b.empty(); b.pop()) printf("%d ", b.back());
}
