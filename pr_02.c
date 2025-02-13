/*  PR 02
    1. error handling
    2. AOS vs SOA
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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
    
}
