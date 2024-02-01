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

#include <cassert>
#include <cstdio>
#include <deque>

using dynarray = std::deque<int>;

int main() {
    dynarray a = {};

    a.push_back(20);
    a.push_front(10);

    for (size_t i = 0; i < a.size(); i++) printf("%d ", a[i]);

    dynarray b = a;

    a.pop_front();
    a.pop_back();

    assert(a.empty());

    for (size_t i = 0; i < a.size(); i++) printf("%d ", a[i]);

    printf("%d ", *std::find(b.begin(), b.end(), 10));

    b.clear();

    for (size_t i = 0; i < b.size(); i++) printf("%d ", b[i]);
}
