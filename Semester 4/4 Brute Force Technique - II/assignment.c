#include<stdlib.h>
#include<stdio.h>

#define MAX 10

int n;
int c[MAX][MAX];
int p[MAX];
int min_cost = 1000;
int min_perm[MAX];

void assign(int i, int cost) {
    if ( i == n) {
        if ( cost < min_cost) {
            min_cost = cost;
            for (int y = 0; y < n; y++) {
                min_perm[y] = p[y];
            }
        }
        printf("Permutation: ");
        for ( int j = 0; j < n; j++) {
            printf("%d ", p[j]);
        }
        printf("Cost = %d \n", cost);
        return;
    }
    for (int j = 0; j < n; j++) {
        if (!p[j]) {
            p[j] = i+1;
            assign(i+1, cost + c[i][j]);
            p[j] = 0;
        }
    }
}

int main() {
    printf("Enter the vertex: ");
    scanf("%d", &n);
    printf("Enter the matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    assign(0,0);
    printf("Minimum cost = %d\n", min_cost);
    printf("Permutation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", min_perm[i]);
    }
    printf("\n");
    return 0;

}
