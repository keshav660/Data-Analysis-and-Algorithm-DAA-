#include <stdio.h>

void fracKnapsack(int n, float weight[], float profit[], float capacity) {
    float x[20], tp = 0; 
    int i;
    float ratio[20], temp;

    // Calculate profit/weight ratio
    for (i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    // Sort by ratio in descending order
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratio
                temp = ratio[i]; ratio[i] = ratio[j]; ratio[j] = temp;
                // Swap weight
                temp = weight[i]; weight[i] = weight[j]; weight[j] = temp;
                // Swap profit
                temp = profit[i]; profit[i] = profit[j]; profit[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) x[i] = 0.0;

    float u = capacity;
    for (i = 0; i < n; i++) {
        if (weight[i] > u)
            break;
        x[i] = 1.0;
        tp += profit[i];
        u -= weight[i];
    }

    if (i < n) {
        x[i] = u / weight[i];
        tp += x[i] * profit[i];
    }

    printf("\nItem fractions included:\n");
    for (i = 0; i < n; i++)
        printf("Item %d: %.2f\n", i + 1, x[i]);

    printf("\nMaximum value in Fractional Knapsack = %.2f\n", tp);
}

int main() {
    int n;
    float weight[20], profit[20], capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &weight[i]);

    printf("Enter the profits of the items:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &profit[i]);

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    fracKnapsack(n, weight, profit, capacity);

    return 0;
}
// Enter the number of items: 3
// Enter the weights of the items:
// 10 20 30
// Enter the profits of the items:
// 60 100 120
// Enter the capacity of the knapsack: 50
// Item fractions included:
// Item 1: 1.00
// Item 2: 1.00
// Item 3: 0.33

// Maximum value in Fractional Knapsack = 240.00
