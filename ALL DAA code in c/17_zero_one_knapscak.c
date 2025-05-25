#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int w[] = {2, 3, 4, 5};
    int v[] = {3, 4, 5, 6};
    int W = 5, n = 4;
    int K[10][10];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (w[i - 1] <= j)
                K[i][j] = max(v[i - 1] + K[i - 1][j - w[i - 1]], K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    }

    printf("Maximum value = %d\n", K[n][W]);
    return 0;
}
