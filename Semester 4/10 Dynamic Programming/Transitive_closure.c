#include<stdio.h>
#include<stdlib.h>

int max = 2;
void transitive_closure(int adj_mat[][max], int t[][max], int n, int *count) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj_mat[i][j] == 1) {
                t[i][j] = 1;
                (*count)++;
            } else {
                t[i][j] = 0;
            }
        }
    }
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (t[i][k] && t[k][j] && !t[i][j]) {
                    t[i][j] = 1;
                    (*count)++;
                }
            }
        }
    }
}

int main() {
    int nodes, count = 0;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);
    max = nodes;
    int adj_matr[max][max], tr[max][max], i, k, j;
    printf("Enter the adjacency matrix: \n");
    for (i = 0; i < max; i++) {
        for (j = 0; j < max; j++) {
            scanf("%d", &adj_matr[i][j]);
        }
    }
    printf("The Transitive closure of the matrix is: \n");
    transitive_closure(adj_matr, tr, max, &count);
    for (i = 0; i < max; i++) {
        for (j = 0; j < max; j++) 
            printf("%d ", tr[i][j]);
        printf("\n");
    }
    printf("Number of key comparisons: %d\n", count);
}
