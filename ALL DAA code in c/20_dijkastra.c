#include <stdio.h>

#define INF 999

void dijkstra(int n, int graph[10][10], int start) {
    int dist[10], visited[10] = {0}, i, j, u = 0, min;

    // Initialize distance array with direct distances from start
    for (i = 0; i < n; i++)
        dist[i] = graph[start][i];

    visited[start] = 1;

    // Loop to find shortest path for all vertices
    for (i = 1; i < n; i++) {
        min = INF;

        // Find the vertex with the smallest distance
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        // Update distance values of adjacent vertices
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    // Print the shortest distances
    printf("\nShortest distances from node %d:\n", start);
    for (i = 0; i < n; i++)
        printf("To %d = %d\n", i, dist[i]);
}

int main() {
    int n, i, j, start, graph[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 999 for no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    dijkstra(n, graph, start);

    return 0;
}
