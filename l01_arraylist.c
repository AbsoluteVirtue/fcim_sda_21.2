/*
Создать интерфейс для динамического массива.

1. initialize -- инициализирует массив
2. resize     -- изменяет размер массива на заданный
3. at         -- возвращает элемент массива по заданному индексу, с проверкой выхода за пределы массива
4. push_back  -- добавляет новый элемент в конец массива
5. insert     -- добавляет новый элемент по индексу
6. pop_back   -- удаляет последний элемент массива
7. remove     -- удаляет элемент по индексу
8. clear      -- опустошает массив (приводит в соответствие с initialize)

Динамический массив организовать как структуру согласно варианту.
*/

// var a
typedef struct arraylist {
    int *data;
    size_t size;
    size_t capacity;
} arraylist;
// var b
typedef struct arraylistII {
    int *data;
    int *size;
    int *capacity;
};

void push_back(arraylist *x, int value) {
    if (x->capacity <= x->size) {
        x->capacity = (x->capacity ? x->capacity * 2 : 1);
        x->data = (int*)realloc(x->data, sizeof(int) * x->capacity);
        if (x->data == NULL) return;
    }
    x->data[x->size] = value;
    x->size++;
}

void test_push_back() {
    arraylist a;
    a.capacity = 0;
    a.size = 0;
    a.data = NULL;
    push_back(&a, 1);
    assert(a.data != NULL);
    assert(a.size == 1);
    assert(a.capacity == 1);
    assert(a.data[0] == 1); 
    push_back(&a, 2);
    assert(a.capacity == 2);
    assert(a.size == 2);
    assert(a.data != NULL);
    assert(a.data[1] == 2);
}

int main(void) {
  
    arraylist a;

    for (size_t i = 0; i < a.size; i++)
    {
        printf("%d ", a.data[i]);
    }
 
}
