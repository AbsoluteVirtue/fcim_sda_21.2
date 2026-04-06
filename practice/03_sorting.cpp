// see: Quicksort, Cormen et al. p. 183
// see: Merge-sort, Cormen et al. p. 36
#include <cstddef>
#include <cstdio>

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

void merge(int (&A)[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q; 

    int left[n1 + 1];
    int right[n2 + 1];

    left[n1] = 123456798;
    right[n2] = 123456798;

    int i = 0, j = 0;

    for ( ; i < n1; i++)
        left[i] = A[p + i];
    for ( ; j < n2; j++)
        right[j] = A[q + j + 1];

    i = 0;
    j = 0;

    for (int k = p; k <= r; k++) {
        if (left[i] <= right[j]) {
            A[k] = left[i];
            i++;
        } else {
            A[k] = right[j];
            j++;
        }
    }
}

void mergesort(int (&A)[], int p, int r) {
    if (p < r)
    {
        int q = ((p + r) / 2);
        mergesort(A, p, q);
        mergesort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main(void) {
    int a[] = {-1, 13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21, -1};
    size_t n = 12;
    quicksort(a, 1, n);
    for (size_t i = 1; i <= n; ++i) printf("%d ", a[i]);
}
