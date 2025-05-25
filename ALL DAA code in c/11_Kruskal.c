#include <stdio.h>

int parent[100];

int find(int i) {
    while (parent[i]) i = parent[i];
    return i;
}

void unionn(int i, int j) {
    parent[j] = i;
}

int main() {
    int cost[10][10] = {
        {999, 2, 999, 6},
        {2, 999, 3, 8},
        {999, 3, 999, 999},
        {6, 8, 999, 999}
    };
    int n = 4, mincost = 0, ne = 1;

    while (ne < n) {
        int min = 999, a = -1, b = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        int u = find(a);
        int v = find(b);
        if (u != v) {
            printf("Edge %d: (%d,%d) cost:%d\n", ne++, a, b, min);
            mincost += min;
            unionn(u, v);
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("Minimum cost = %d\n", mincost);
    return 0;
}
