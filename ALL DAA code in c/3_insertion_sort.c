#include <stdio.h>

void insertionSort(int A[], int n) {
    int j, i, key;
    for (j = 1; j < n; j++) {
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int A[] = {20, 30, 10, 50, 40};
    int n = sizeof(A) / sizeof(A[0]);
    insertionSort(A, n);
    printArray(A, n);
    return 0;
}
