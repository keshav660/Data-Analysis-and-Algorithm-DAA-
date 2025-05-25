#include <stdio.h>

void bubbleSort(int A[], int n) {
    int k, ptr, temp;
    for (k = 1; k < n; k++) {
        ptr = 0;
        while (ptr < n - k) {
            if (A[ptr] > A[ptr + 1]) {
                temp = A[ptr];
                A[ptr] = A[ptr + 1];
                A[ptr + 1] = temp;
            }
            ptr = ptr + 1;
        }
    }
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int A[] = {30, 10, 50, 20, 60};
    int n = sizeof(A) / sizeof(A[0]);
    bubbleSort(A, n);
    printArray(A, n);
    return 0;
}
