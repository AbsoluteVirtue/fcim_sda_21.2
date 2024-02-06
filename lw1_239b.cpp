// https://godbolt.org/z/bTGsPMhcW

// stack
//      cons n          - инициализировать массив заданной длины
//      pop             - удалить последний добавленный элемент массива
//      push v          - добавить элемент в массив за последним добавленным
//      top             - найти последний добавленный элемент массива
//      size            - определить длину массива
//      empty           - проверить наличие элементов в массиве
//      eq a b          - сравнить два массива

#include <cassert>
#include <cstdio>
#include <stack>

using dynarray = std::stack<int>;

int main() {
    dynarray a = {};

    a.push(30);
    a.push(20);
    a.push(10);

    dynarray b = a;

    assert(a == b);

    for ( ; !a.empty(); a.pop()) printf("%d ", a.top());

    assert(a.empty());

    assert(3 == b.size());

    for ( ; !b.empty(); b.pop()) printf("%d ", b.top());

}
