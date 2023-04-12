#include<stdio.h>
#include<stdlib.h>
int a[10][10], d[10][10], n, count;

int min(int a, int b) {
    count++;
    return (a < b) ? a : b;
}

void path() {
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    int i, j;
    count = 0;
    printf("Enter the number of rows or column: ");
    scanf("%d", &n);
    printf("\nEnter the cost matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            d[i][j] = a[i][j];
        }
    }
    path();
    printf("\nThe Final Distance Matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    printf("Number of key comparisons: %d\n", count);
    return 0;
}
