#include <stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity) {
    float x[20], tp = 0;
    int i, j, u;
    u = capacity;

    for (i = 0; i < n; i++)
        x[i] = 0.0;

    for (i = 0; i < n; i++) {
        if (weight[i] > u)
            break;
        else {
            x[i] = 1.0;
            tp += profit[i];
            u -= weight[i];
        }
    }

    if (i < n)
        x[i] = u / weight[i];

    tp += (x[i] * profit[i]);

    printf("Total profit = %.2f\n", tp);
}

int main() {
    int n = 3;
    float weight[] = {10, 20, 30};
    float profit[] = {60, 100, 120};
    float capacity = 50;

    knapsack(n, weight, profit, capacity);
    return 0;
}
