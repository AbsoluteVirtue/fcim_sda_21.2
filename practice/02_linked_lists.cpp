#include <cstdio>

struct pair {
    int head  {0};
    pair* tail{nullptr};
};

void print_list(pair *begin) {
    if (begin) {
        printf("%d ", begin->head);
        print_list(begin->tail);
    }
}

// почему массивы и почему списки
// https://www.youtube.com/watch?v=ShSGHb65f3M

int main() {
    
    int a[5] = {1, 2, 3, 4, 5};
    {   // итерация по массиву
        int *begin = &a[0];
        int *end = &a[5];
        for (; begin != end; begin++)
            printf("%d ", *begin);
        
    }
     
    pair *p = new pair;
    {   // создание списка
        auto begin = p;
        for (size_t i = 0; i < 5; i++)
        {
            // *begin.tail;
            begin->head = i + 1;
            begin->tail = new pair;
            begin = begin->tail;
        }
    }    
    
    {
        auto begin = p;
        for ( ; begin != nullptr; begin = begin->tail) 
            printf("%d ", begin->head);
    }

    // рекурсия по списку
    print_list(p);

    {   // удаление списка
        auto begin = p;
        while (begin) {
            auto t = begin;
            begin = begin->tail;
            delete t;
        }
        p = nullptr;
    }

}
