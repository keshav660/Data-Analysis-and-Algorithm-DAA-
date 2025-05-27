#include <stdio.h>

#define INF 999

void prim(int n, int cost[10][10]) {
    int selected[10] = {0}, i, j, u, v, min, edges = 0;

    selected[0] = 1;  // Start from vertex 0

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        min = INF;

        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", u, v, cost[u][v]);
        selected[v] = 1;
        edges++;
    }
}

int main() {
    int n, i, j, cost[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 999 for no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    prim(n, cost);

    return 0;
}
// Enter number of vertices: 4
// Enter the cost adjacency matrix (use 999 for no edge):
// 999 2   999 6
// 2   999 3   8
// 999 3   999 1
// 6   8   1   999

// Edges in Minimum Spanning Tree:
// 2 - 3 : 1
// 1 - 2 : 3
// 0 - 1 : 2
