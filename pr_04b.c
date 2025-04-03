// see: Quicksort, Cormen et al. p. 183
// see: Merge-sort, Cormen et al. p. 36
#include <stddef.h>

#define swap(T, x, y) { T tmp = x; x = y; y = tmp; }

size_t partition(int *a, size_t p, size_t r) {
    int x = a[r];
    size_t i = p - 1;
    for (size_t j = p; j <= r - 1; j++) {
        if (a[j] <= x) {
            i = i + 1;
            swap(int, a[i], a[j]);
        }
    }
    swap(int, a[i + 1], a[r]);
    return i + 1;
}

void quicksort(int *a, size_t p, size_t r) {
    if (p < r) {
        size_t q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}

#include <stdio.h>

int main(void) {
    int a[] = {-1, 13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21, -1};
    size_t n = 12;
    quicksort(a, 1, n);
    for (size_t i = 1; i <= n; ++i) printf("%d ", a[i]);
}

////////////////////////////////////////////////////////////////////
// see: Bellman-Ford, Cormen et al. p. 612
#include <limits.h>


typedef struct vertex
{
    int d;
    struct vertex *pi;
} vertex;

typedef struct edge {
    vertex *u;
    vertex *v;
    int w;
} edge;

typedef struct graph {
    edge e[100];
    size_t E;
    vertex v[100];
    size_t V;
} graph;

void initialize(graph *G, vertex *s) {
    for (size_t i = 0; i < G->V; i++)
    {
        G->v[i].d = INT_MAX;
        G->v[i].pi = NULL;
    }
    s->d = 0;
}

void relax(vertex *u, vertex *v, int w) {
    if (v->d > u->d + w) {
        v->d = u->d + w;
        v->pi = u;
    }
}

int bellman(graph *G, vertex *s) {
    initialize(G, s);
    for (size_t j = 0; j < G->V - 1; j++)
    {
        for (size_t i = 0; i < G->E; i++)
        {
            relax(G->e[i].u, G->e[i].v, G->e[i].w);
        }
    }
    for (size_t i = 0; i < G->E; i++)
    {
        if (G->e[i].v->d > G->e[i].u->d + G->e[i].w) return 0;
    }
    return 1;
}
