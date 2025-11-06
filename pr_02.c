#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node; 

// error handling
// error code as argument
void build_list_a(node **head, int array[], size_t n, int *error) {
    node *current = NULL;
    for (size_t i = 0; i < n; i++)
    {
        node *tmp = malloc(sizeof(node));
        // error handling:
        if (tmp == NULL) { *error = -1; return; } // set error and exit

        tmp->data = array[i];
        tmp->next = NULL;
        if (current) current->next = tmp;
        else *head = tmp;
        current = tmp;
    }
    // exit normally
}

// error code as return value
int build_list_b(node **head, int array[], size_t n) {
    node *current = NULL;
    for (size_t i = 0; i < n; i++)
    {
        node *tmp = malloc(sizeof(node));
        // error handling:
        if (tmp == NULL) { return -1; } // set error and exit

        tmp->data = array[i];
        tmp->next = NULL;
        if (current) current->next = tmp;
        else *head = tmp;
        current = tmp;
    }
    return 0; // exit normally
}

typedef struct optional {
    int value;
    int error;
} optional;

optional build_list_c(node **head, int array[], size_t n) {
    node *current = NULL;
    for (size_t i = 0; i < n; i++)
    {
        node *tmp = malloc(sizeof(node));
        // error handling:
        if (tmp == NULL) { return (optional) {0, -1}; } // set error and exit

        tmp->data = array[i];
        tmp->next = NULL;
        if (current) current->next = tmp;
        else *head = tmp;
        current = tmp;
    }
    return (optional) {1, 0}; // exit normally
}

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

#define X 1
#ifdef A    
    int err = 0;
    build_list_a(&head, array, 5, &err);
    assert(!err);
#elif B
    int err = build_list_b(&head, array, 5);
    assert(!err);
#elif C
    optional res = build_list_c(&head, array, 5);
    assert(!res.error);
#endif

    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
}
