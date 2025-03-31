#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct node {
    int x;
    struct node *left;
    struct node *right;
} node; 

#define count 10

void print(node *n) {
    if (n == NULL) return;
    // pre
    print(n->left);
    // in
    printf("%d ", n->x);
    print(n->right);
    // post
}

void insert(node **n, int v) {
    if (!*n) {
        *n = malloc(sizeof(node));
        (*n)->x = v;
        (*n)->right = NULL;
        (*n)->left = NULL;
        return;
    }
    if (v > (*n)->x) {
        insert(&(*n)->right, v);
    } else {
        insert(&(*n)->left, v);
    }
}

void clear(node **n) {
    if (NULL == *n) return;
    clear(&(*n)->left);
    clear(&(*n)->right);
    free(*n);
    *n = NULL;
}

int main(void) {

    node *root = NULL;
    int a[count] = {6, 3, 8, 7, 2, 5, 1, 0, 9, 4};
    for (size_t i = 0; i < count; i++)
    {
        insert(&root, a[i]);
    }
    
    print(root);

    clear(&root);
    clear(&root);
    root = NULL;
}
