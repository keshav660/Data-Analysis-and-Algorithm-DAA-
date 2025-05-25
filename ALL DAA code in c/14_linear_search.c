#include <stdio.h>

int main() {
    int a[] = {4, 2, 7, 1, 9};
    int n = 5, key = 7, found = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found\n");

    return 0;
}
