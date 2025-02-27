#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
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

