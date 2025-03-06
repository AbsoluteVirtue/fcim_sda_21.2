/*
1. resize -- изменяет размер списка на заданный
2. initialize -- инициализирует список
3. front -- возвращает элемент в начале списка
4. back -- возвращает элемент в конце списка
5. push_front -- добавляет новый элемент в начало списка
6. pop_front -- удаляет первый элемент списка
7. push_back -- добавляет новый элемент в конец списка
8. pop_back -- удаляет последний элемент списка
9. clear -- опустошает список (приводит в соответствие с initialize)
10. size -- возвращает количество элементов в массиве
11. insert -- добавляет элемент в список по ссылке
12. erase -- удаляет элемент из списка по ссылке
*/

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// var a,  https://en.cppreference.com/w/cpp/container/forward_list
typedef struct node {
    int data;
    struct node *next;
} node;

// var b,  https://en.cppreference.com/w/cpp/container/list
typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;

int main(void) {

    node first = {1, NULL};
    node second = {2, NULL};
    first.next = &second;

    node third = {3, NULL};
    second.next = &third;

    node *head = &first;
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }

    int array[] = {1, 2, 3, 4, 5};
    node *current = NULL;
    for (size_t i = 0; i < 5; i++)
    {
        node *tmp = malloc(sizeof(node));
        tmp->data = array[i];
        tmp->next = NULL;
        if (current) current->next = tmp;
        else head = tmp;
        current = tmp;
    }
    
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

