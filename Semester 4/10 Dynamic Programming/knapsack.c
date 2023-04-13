#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10
#define MAX_W 100

int n, W, w[MAX_N], v[MAX_N], V[MAX_N + 1][MAX_W + 1], x[MAX_N + 1];

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

void knapsack() {
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) { 
            if (i == 0 || j == 0)
                V[i][j] = 0;
            else if (j < w[i])
                V[i][j] = V[i - 1][j];
            else
                V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
            printf("%d\t", V[i][j]);
        }
        printf("\n");
    }
}

void printSolution() {
    int i, j;
    i = n;
    j = W;
    while (i != 0 && j != 0) {
        if (V[i][j] != V[i - 1][j]) {
            x[i] = 1;
            j = j - w[i];
        }
        i--;
    }
}

int main() {
    int i;
    printf("Enter no. of objects: ");
    scanf("%d", &n);
    printf("\nEnter the knapsack capacity: ");
    scanf("%d", &W);
    printf("Enter the weights of the objects: \n");
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("\nEnter the profits of the objects: \n");
    for (i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    knapsack();
    printSolution();
    printf("\nObject\tWeight\tProfit\n");
    for (i = 1; i <= n; i++) {
        if (x[i] == 1)
            printf("%d\t%d\t%d\n", i, w[i], v[i]);
    }
    printf("\nMax profit is: %d\n", V[n][W]);
    return 0;
}
