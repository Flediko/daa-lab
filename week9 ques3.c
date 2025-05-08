#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void minHeapify(int heap[], int n, int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && heap[l] < heap[smallest]) smallest = l;
    if (r < n && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) {
        int temp = heap[i]; heap[i] = heap[smallest]; heap[smallest] = temp;
        minHeapify(heap, n, smallest);
    }
}

int extractMin(int heap[], int *n) {
    int min = heap[0];
    heap[0] = heap[--(*n)];
    minHeapify(heap, *n, 0);
    return min;
}

void insertHeap(int heap[], int *n, int val) {
    int i = (*n)++;
    heap[i] = val;
    while (i && heap[i] < heap[(i-1)/2]) {
        int temp = heap[i]; heap[i] = heap[(i-1)/2]; heap[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

int main() {
    int n, files[MAX], heap[MAX];
    printf("Enter number of files: ");
    scanf("%d", &n);
    
    printf("Enter file sizes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &files[i]);
        heap[i] = files[i];
    }
    
    int heapSize = n, totalCost = 0;
    for (int i = (n/2)-1; i >= 0; i--) minHeapify(heap, n, i);
    
    while (heapSize > 1) {
        int a = extractMin(heap, &heapSize);
        int b = extractMin(heap, &heapSize);
        int merged = a + b;
        totalCost += merged;
        insertHeap(heap, &heapSize, merged);
    }
    
    printf("Minimum merge cost = %d\n", totalCost);
    return 0;
}
