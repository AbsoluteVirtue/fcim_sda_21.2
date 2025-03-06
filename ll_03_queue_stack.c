/*
Реализовать стек или очередь на базе одной из прерыдущих лабораторных, для стека:

1. push -- добавляет новое значение на вершину
2. pop -- удаляет значение на вершине
3. top -- возвращает текущее значение на вершине
4. size -- возвращает текущее количество элементов
5. empty -- возвращает true, если контейнер пуст

для очереди:

1. push -- добавляет новое значение в конец
2. pop -- удаляет значение из начала
3. front -- возвращает значение в начале
4. back -- возвращает значение в конце
5. size -- возвращает текущее количество элементов
6. empty -- возвращает true, если контейнер пуст

*/

// var a, https://en.cppreference.com/w/cpp/container/stack
typedef struct stack { /* массив или связный список */ } stack; 
// var b, https://en.cppreference.com/w/cpp/container/queue
typedef struct queue { /* массив или связный список */ } queue;

int main(void) {

    stack s = {0};
    for (size_t i = 0; i < 5; i++) push(&s, i);
    for (; !empty(&s); pop(&s)) printf("%d ", top(s));
    // 4 3 2 1 0
    
    queue q = {0};
    for (size_t i = 0; i < 5; i++) push(&q, i);
    for (; !empty(&q); pop(&q)) printf("%d ", front(q));
    // 0 1 2 3 4

}
