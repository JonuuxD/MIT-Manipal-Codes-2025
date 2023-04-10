#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int count = 0;
void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* heap, int n) {
    if (n >=1 ) {
        int temp;
        if (n>1 && heap[n/2] < heap[n]) {
            swap(heap + n/2, heap + n);
            count++;
        }
        if (heap[2*n] > heap[n]) {
            swap(heap + 2*n, heap+n);
            count++;
        }
        if(heap[2*n+1] > heap[n]) {
            swap(heap + 2*n+1, heap+n);
            count++;
        }
        return heapify(heap, n/2);
    }
}

int *heapconst(int *arr, int n) {
    int *heap;
    heap = (int*) calloc (MAX, sizeof(int));
    for ( int i = 1; i <= n; i++) {
        heap[i] = arr[i];
        heapify(heap, i);
    }
    return heap;
}

int main() {
    int *arr, n;
    printf("Enter the length of array: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    arr = (int *) malloc(n * sizeof(int));
    for (int i = 1; i <= n; i++)
        scanf("%d", arr+i);
    printf("Heap obtained: ");
    int* heap = heapconst(arr, n);
    for (int i = 1; i <= n; i++)
        printf("%d ", heap[i]);
    printf("\n");
    printf("The operation count is: %d", count);
    return 0;
}
