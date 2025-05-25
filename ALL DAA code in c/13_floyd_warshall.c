#include <stdio.h>

int main() {
    int n = 4;
    int dist[4][4] = {
        {0, 5, 999, 10},
        {999, 0, 3, 999},
        {999, 999, 0, 1},
        {999, 999, 999, 0}
    };
    
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", dist[i][j]);
        printf("\n");
    }
    return 0;
}
