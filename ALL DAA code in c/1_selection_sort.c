#include <stdio.h>

void selectionSort(int A[], int n) {
    int k, j, min, loc, temp;
    for (k = 0; k < n - 1; k++) {
        min = A[k];
        loc = k;
        for (j = k + 1; j < n; j++) {
            if (min > A[j]) {
                min = A[j];
                loc = j;
            }
        }
        // Swap A[k] and A[loc]
        temp = A[k];
        A[k] = A[loc];
        A[loc] = temp;
    }
}
void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main() {
    int A[] = {64, 25, 12, 22, 11};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array:\n");
    printArray(A, n);

    selectionSort(A, n);

    printf("Sorted array:\n");
    printArray(A, n);

    return 0;
}
