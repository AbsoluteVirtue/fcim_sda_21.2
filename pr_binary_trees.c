#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} node;

typedef node * tree;

void insert(tree*, int);
void clear(tree*);
void print(tree);
tree find(tree, int);

int main( void ) {
    tree a = NULL;

    insert(&a, 9);
    insert(&a, 1);
    insert(&a, 5);
    insert(&a, 7);
    insert(&a, 3);

    print(a);

    clear(&a);
}

void print(tree root) {
    if (NULL == root) return;
    print(root->left);
    printf("%d ", root->value);
    print(root->right);
}

void insert(tree* root, int val) {
    if (NULL == *root) {
        *root = malloc(sizeof(node));
        (*root)->value = val;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }
    if ((*root)->value < val) {
        insert(&((*root)->right), val);
    } else if ((*root)->value > val) {
        insert(&((*root)->left), val);
    }
}

void clear(tree *root) {
    if (NULL == *root) return;
    clear(&((*root)->left));
    clear(&((*root)->right));
    free(*root);
    *root = NULL;
}

tree find(tree root, int val) {
    if (NULL == root) return NULL;
    if (val < root->value) {
        return find(root->left, val);
    } else if (val > root->value) {
        return find(root->right, val);
    }
    return root;
}
