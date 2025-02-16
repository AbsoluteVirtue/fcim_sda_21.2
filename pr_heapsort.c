#include <stdio.h>

void heapify1(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify1(arr, n, largest);
    }
}

void heapify2(int arr[], int i, int n) { 
	int smallest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] < arr[smallest]) {
        smallest = l;
    }

	if (r < n && arr[r] < arr[smallest]) {
        smallest = r;
    }

	if (smallest != i) { 
		swap(arr[i], arr[smallest]); 
		heapify2(arr, smallest, n); 
	} 
} 

void build_heap(int arr[], int n)  {
	for (int i = n; i >= 0; i--) { 
		heapify2(arr, i, n); 
	} 
}

void heap_sort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify1(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify1(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heap_sort(arr, n);

    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
}
