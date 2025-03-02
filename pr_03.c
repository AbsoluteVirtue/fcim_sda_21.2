// https://github.com/ThePrimeagen/zig-deez-structures/blob/master/src/main.zig
// https://godbolt.org/z/9n9nnq1xv

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9

typedef enum {
    UNKNOWN,
    DISCOVERED,
    VISITED,
} status;

bool empty(void*);

typedef struct _node {
    int value;
    struct _node *next;
} node;

typedef struct {
    node *front;
    node *back;
} queue;

int  front(queue);
void enqueue(queue*, int);
void dequeue(queue*);

typedef struct {
    node *head;
} stack;

int  top(stack);
void push(stack*, int);
void pop(stack*);

int main() {

    bool adj_matrix[N][N] = {
		{0, 1, 0, 0, 0, 0, 0, 1, 0},
		{1, 0, 1, 0, 0, 0, 0, 1, 0},
		{0, 1, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 1, 0, 0, 0, 1, 0, 1},
		{0, 0, 0, 0, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 0, 1, 0},
		{1, 1, 1, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0},
	};

    status nodes[N] = {UNKNOWN};

    // Breadth-first search; 
    // on binary trees: level-ordered traversal / queue-based;
    // spanning tree w/ cross-edges

    queue Q = {NULL, NULL};
    enqueue(&Q, 0);
    while (!empty(&Q)) {
        int current = front(Q);
        dequeue(&Q);
        nodes[current] = VISITED;
        for (size_t i = 0; i < N; i++) {
            if (adj_matrix[current][i] && nodes[i] == UNKNOWN) {
                enqueue(&Q, i);
                nodes[i] = DISCOVERED;
            }
        }
        printf("%d ", current);
    }

    // 0 1 7 2 6 3 4 8 5

    printf("\n");
    memset(nodes, UNKNOWN, N * sizeof(UNKNOWN));

    // Depth-first search; 
    // on binary trees: pre-ordered traversal / stack-based;
    // spanning tree w/ back-edges

    stack S = {NULL};
    push(&S, 0);
    while (!empty(&S)) {
        int current = top(S);
        pop(&S);
        if (nodes[current] == VISITED) continue;

        nodes[current] = VISITED;
        for (int i = N - 1; i >= 0; i--) {
            if (adj_matrix[current][i] && nodes[i] != VISITED) {
                push(&S, i);
                nodes[i] = DISCOVERED;
            }
        }
        printf("%d ", current);
    }

    // 0 1 2 3 6 4 5 7 8

}

int front(queue q) {
    assert(q.front);
    return q.front->value;
}

void enqueue(queue *q, int v) {
    node *tmp = malloc(sizeof(node));
    assert(tmp);
    tmp->value = v;
    tmp->next = NULL;
    if (q->back) {
        q->back->next = tmp;
    }
    if (!q->front) {
        q->front = tmp;
    }
    q->back = tmp;
}

void dequeue(queue *q) {
    node *tmp = q->front;
    if (q->front) {
        q->front = q->front->next;
    }
    if (q->back == tmp) {
        q->back = q->front;
    }
    free(tmp);
}

int top(stack s) {
    assert(s.head);
    return s.head->value;
}

void push(stack *s, int v) {
    node *tmp = malloc(sizeof(node));
    assert(tmp);
    tmp->value = v;
    tmp->next = s->head;
    s->head = tmp;
}

void pop(stack *s) {
    node *tmp = s->head;
    if (s->head) {
        s->head = s->head->next;
    }
    free(tmp);
}

bool empty(void *c) {
    return NULL == ((stack*)c)->head;
}
