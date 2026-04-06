#include <stdio.h>

#define swap(x, y) { auto t = x; x = y; y = t; }

void heapify(int arr[], int n, int i, auto cmp) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && cmp(arr[l], arr[largest])) {
        largest = l;
    }

    if (r < n && cmp(arr[r], arr[largest])) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, cmp);
    }
}

void heap_sort(int arr[], int n, auto cmp) {
    // build heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, cmp);
    }
    // sort by swap-pop
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, cmp);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heap_sort(arr, n, [] (int x, int y) { return x < y; });

    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
}
