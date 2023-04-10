#include<stdio.h>
#include<stdlib.h>

int a[20][20];
int visited[20];
int f = 0;
int r = -1;
int n;
int q[20];

void bfs(int v,int n) {
    for ( int i = 0; i < n; i++) {
        if ( a[v][i] && !visited[i]) {
            q[++r] = i;
        }
    }
    if (f <= r) {
        visited[q[f]] = 1;
        bfs(q[++f], n);
    }
}

int main() {
    int v;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix: \n");
    for ( int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &v);
    for (int i = 0; i < n; i++) {
        q[i] = 0;
        visited[i] = 0;
    }
    bfs(v, n);

    printf("The reachable order are: ");
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            printf("%d ", i);
        }
    }
    return 0;
}
