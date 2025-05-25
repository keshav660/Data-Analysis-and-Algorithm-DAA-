#include <stdio.h>

void counting_sort(int a[], int n) {
    int output[100], count[100] = {0}, max = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] > max) max = a[i];

    for (int i = 0; i < n; i++)
        count[a[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

int main() {
    int a[] = {4, 2, 2, 8, 3, 3, 1};
    int n = 7;

    counting_sort(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
