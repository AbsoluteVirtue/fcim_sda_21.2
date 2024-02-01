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

#include <cassert>
#include <cstdio>
#include <vector>

using dynarray = std::vector<int>;

int main()
{
    dynarray a = {};

    for (size_t i = 0; i < a.size(); i++) printf("%d ", a[i]);

    a.insert(a.begin(), 10);

    a.push_back(20);

    for (size_t i = 0; i < a.size(); i++) printf("%d ", a[i]);

    dynarray b = a; assert(a == b);

    b.erase(b.begin());

    a.clear();

    for (size_t i = 0; i < a.size(); i++) printf("%d ", a[i]);

    b.clear();

    for (size_t i = 0; i < b.size(); i++) printf("%d ", b[i]);
}
