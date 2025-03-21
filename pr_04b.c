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
