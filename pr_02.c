/*  PR 02
    1. error handling (push_back.realloc, at.operator[])
    2. AOS vs SOA
    3. stack & queue
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
    int i;
    char c;
    double d;
} aos;

typedef struct {
    int i[100];
    char c[100];
    double d[100];
} soa;

typedef struct node {
    int data;
    struct node *next;
} node; 

int main(void) {

    aos array[100];
    soa structure;

    printf("%zu %zu", sizeof(array), sizeof(structure));

//////////////////////

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
