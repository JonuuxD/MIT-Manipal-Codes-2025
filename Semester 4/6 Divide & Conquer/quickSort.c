#include<stdio.h>
#include<stdlib.h>

int opcount = 0;

void printArray(int* A, int n) {
    for ( int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high) {
    int pivot = A[low];
    int i = low+1;
    int j = high;
    int temp;
    do {
        while (A[i] <= pivot) {
            i++;
        }
        while (A[j] > pivot) {
            j--;
        }
        if ( i < j) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }while (i < j);
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high, int n) {
    int partitionIndex;
    if (low < high) {
        partitionIndex = partition(A, low, high);
        printArray(A, n);
        opcount++;
        quickSort(A, low, partitionIndex-1, n);
        opcount++;
        quickSort(A, partitionIndex+1, high, n);
        opcount++;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter the elements: \n");
    for ( int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    printf("\n");
    printArray(A, n);
    quickSort(A, 0, n-1, n);
    printArray(A, n);
    printf("The operation count is: %d\n", opcount);
    return 0;
}
