#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int adj[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES], sorted[MAX_VERTICES];
int num_vertices, top=-1;

void create_graph()
{
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the cost matrix:\n");
    for(i=0; i<num_vertices; i++) {
        for(j=0; j<num_vertices; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
}
void dfs(int v) {
    visited[v] = 1;
    for(int i=0; i<num_vertices; i++) {
        if(adj[v][i] != 0 && visited[i] == 0)
            dfs(i);
    }
    sorted[++top] = v;
}
void topsort(int start) {
    int i, j, k;
    for(i=0; i<num_vertices; i++) {
        visited[i] = 0;
    }
    dfs(start);
    for(i=0; i<num_vertices; i++) {
        if(visited[i] == 0)
            dfs(i);
    }
}

int main() {
    create_graph();
    int start;
    printf("Enter the starting node: ");
    scanf("%d", &start);
    start = start - 1;
    topsort(start);
    printf("Topological Sort: ");
    for(int i=top; i>=0; i--)
        printf("%d ", sorted[i]+1);
    return 0;
}
