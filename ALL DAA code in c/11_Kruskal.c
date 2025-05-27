#include <stdio.h>

int parent[100];  // Adjust size as needed

// Find function with path compression
int find(int i) {
    return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
}

// Kruskal’s algorithm
void kruskal(int n, int e, int u[], int v[], int w[]) {
    // Initialize parent array
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // Bubble sort edges by weight
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (w[j] > w[j + 1]) {
                int temp;

                // Swap weights
                temp = w[j]; w[j] = w[j + 1]; w[j + 1] = temp;

                // Swap u vertices
                temp = u[j]; u[j] = u[j + 1]; u[j + 1] = temp;

                // Swap v vertices
                temp = v[j]; v[j] = v[j + 1]; v[j + 1] = temp;
            }
        }
    }

    // Construct MST
    int count = 0, totalCost = 0;
    printf("\nEdges in Minimum Spanning Tree:\n");
    for (int i = 0; i < e && count < n - 1; i++) {
        int a = find(u[i]);
        int b = find(v[i]);

        // If they belong to different sets, include the edge
        if (a != b) {
            printf("%d - %d : %d\n", u[i], v[i], w[i]);
            totalCost += w[i];
            parent[b] = a;  // Union
            count++;
        }
    }

    printf("Total cost of MST: %d\n", totalCost);
}

// Main function
int main() {
    int n, e;
    int u[100], v[100], w[100];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
    }

    kruskal(n, e, u, v, w);

    return 0;
}
// Enter number of vertices: 4
// Enter number of edges: 5
// Enter edges (u v weight):
// 0 1 10
// 0 2 6
// 0 3 5
// 1 3 15
// 2 3 4
