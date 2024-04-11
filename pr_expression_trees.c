// Поляков, К., "Программирование на языке Си" (2009)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *left, *right;
};

typedef struct node *pnode;

#define NOT_AN_OPERATOR 100

int priority(char c) {
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return NOT_AN_OPERATOR;
}

pnode make_tree(char expr[], int first, int last) {
    int minptr, i, k, ptr;
    int nest = 0;
    pnode tree = malloc(sizeof(struct node));
    if (first == last) {
        tree->data = expr[first];
        tree->left = NULL;
        tree->right = NULL;
        return tree;
    }
    minptr = NOT_AN_OPERATOR;
    for (i = first; i <= last; i++) {
        if (expr[i] == '(') {
            nest++;
            continue;
        }
        if (expr[i] == ')') {
            nest--;
            continue;
        }
        if (nest > 0) continue;

        ptr = priority(expr[i]);
        if (ptr <= minptr) {
            minptr = ptr;
            k = i;
        }
    }
    if (minptr == NOT_AN_OPERATOR &&
        expr[first] == '(' &&
        expr[last] == ')')
    {
        free(tree);
        return make_tree(expr, first + 1, last - 1);
    }

    tree->data = expr[k];
    tree->left = make_tree(expr, first, k - 1);
    tree->right = make_tree(expr, k + 1, last);

    return tree;
}

int eval(pnode root) {
    if (NULL == root) return 0;

    if (root->data >= '0' && '9' >= root->data) return (root->data - '0');

    int left = eval(root->left);
    int right = eval(root->right);

    if ('+' == root->data) return left + right;
    else if ('/' == root->data) return left / right;
    else if ('*' == root->data) return left * right;
    else if ('-' == root->data) return left - right;

    return 0;
}

enum not {prefix, infix, postfix};

void print_tree(pnode tree, int notation) {
    if (!tree) return;
    if (prefix == notation) printf("%c ", tree->data);
    print_tree(tree->left, notation);
    if (infix == notation) printf("%c ", tree->data);
    print_tree(tree->right, notation);
    if (postfix == notation) printf("%c ", tree->data);
}

int main() {
    char s[] = "((1+((2+3)*(4+(5/6))))+((2*3)*(4-6)))";
    pnode tree = make_tree(s, 0, strlen(s) - 1);
    print_tree(tree, postfix);
    printf("\n%d " , eval(tree));
}
