#include <cstddef>
#include <cassert>
#include <cstdlib>
#include <cstdio>
// #include <print>

// абстрактный тип данных

typedef struct valarray {
    int *data       {nullptr};
    size_t size     {0};
    size_t capacity {0};
} valarray;

void push_back(valarray *p, int value) {
    assert(p);

    if (p->size == p->capacity) {
        p->capacity = p->capacity 
                    ? p->capacity * 2 
                    : 1;
        p->data = (int*)
            std::malloc(sizeof(int) * p->capacity);
    }
    p->data[p->size] = value;
    p->size++;
}

struct vector {
private:
    int *data       {nullptr};
    int *size       {nullptr};
    int *capacity   {nullptr};
public:
    void push_back(auto value) {
        if (size == capacity) {
            auto t = (size - data);
            auto n = capacity - data;
            n = n ? n * 2 : 1;
            data = new int[n];
            capacity = data + n;
            size = data + t;
        }
        auto t = size - data;
        data[t] = value;
        size++;
    }
    std::ptrdiff_t len() {
        return size - data;
    }
};

int main() {

    valarray a;

    push_back(&a, 10);
    push_back(&a, 20);
    push_back(&a, 40);
    push_back(&a, 80);
    
    vector b;

    std::printf("%zu ", b.len());

    b.push_back(10);
    b.push_back(20);
    b.push_back(40);
    b.push_back(80);

    std::printf("%zu", b.len());
}
