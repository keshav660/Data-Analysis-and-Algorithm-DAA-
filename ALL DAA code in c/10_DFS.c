#include <stdio.h>

void DFS(int graph[10][10], int n, int node, int visited[]) {
    visited[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < n; i++) {
        if (graph[node][i] && !visited[i]) {
            DFS(graph, n, i, visited);
        }
    }
}

int main() {
    int graph[10][10] = {
        {0,1,1,0},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,0}
    };
    int visited[10] = {0};
    DFS(graph, 4, 0, visited);
    return 0;
}
