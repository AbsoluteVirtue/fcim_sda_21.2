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
void clear(list);

int main() {
    list a = cons(5);

    list b = cons(size(a));

    clear(a); clear(b);

    assert(empty(a));

}

list cons(size_t n) {
    list r = { NULL, n };
    struct node *p = malloc(sizeof(struct node));
    while(n > 0) {
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

void clear(list a) {

}
