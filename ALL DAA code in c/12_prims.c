#include <stdio.h>

int main() {
    int cost[10][10] = {
        {999, 2, 999, 6},
        {2, 999, 3, 8},
        {999, 3, 999, 999},
        {6, 8, 999, 999}
    };
    int n = 4, visited[10] = {0}, ne = 0, mincost = 0;
    visited[0] = 1;

    while (ne < n - 1) {
        int min = 999, a = -1, b = -1;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1) {
            printf("Edge %d: (%d,%d) cost:%d\n", ne + 1, a, b, min);
            visited[b] = 1;
            mincost += min;
            ne++;
        }
    }
    printf("Minimum cost = %d\n", mincost);
    return 0;
}
