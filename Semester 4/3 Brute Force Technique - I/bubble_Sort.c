#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, opcount = 0, temp;
    printf("Enter the numbers in the array: ");
    scanf("%d", &n);
    int a[n];

    printf("Enter the elements: \n");
    for (int y = 0; y < n; y++) {
        printf("Enter elements at %d: ", y+1);
        scanf("%d", &a[y]);
    }
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            if (a[j] > a[j+1]) {
                opcount ++;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("Sorted array is: ");
    for (int x = 0; x < n; x++) {
        printf("%d", a[x]);
    }
    printf("\n Opcount = %d", opcount);
}
