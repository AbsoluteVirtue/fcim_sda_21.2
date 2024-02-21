#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

typedef struct list {
    struct node *head;
    size_t size;
} list;

list cons(size_t);
size_t size(list);
bool empty(list);
void clear(list*);
void for_each(list*, void(*)(int*, int));

void print(int *ref, int x) {
    printf("%d ", *ref);
}

void assign(int *ref, int x) {
    *ref = x;
}

int main() {
    list a = cons(5);

    for_each(&a, assign);
    for_each(&a, print);

    list b = cons(size(a));

    for_each(&b, assign);
    for_each(&b, print);

    clear(&a); clear(&b);

    assert(empty(a));
    assert(empty(b));
}

void for_each(list *a, void(*f)(int *, int)) {
    struct node *tmp = a->head;
    while(tmp) {
        f(&(tmp->value), 0);
        tmp = tmp->next;
    }
}

list cons(size_t n) {
    list r = { NULL, n };
    struct node *p = malloc(sizeof(struct node));
    p->next = NULL;
    while(n > 1) {
        struct node *tmp = malloc(sizeof(struct node));
        tmp->next = p;
        p = tmp;
        n--;
    }
    r.head = p;
    return r;
}

size_t size(list a) {
    return a.size;
}

bool empty(list a) {
    return !size(a);
}

void clear(list *a) {
    while(a->head) {
        struct node *tmp = a->head;
        a->head = a->head->next;
        free(tmp);
    }
    a->size = 0;
}
