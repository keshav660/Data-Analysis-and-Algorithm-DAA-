#include <stdio.h>

int main() {
    int a[] = {1, 3, 5, 7, 9};
    int n = 5, key = 7, low = 0, high = n - 1, mid, found = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key) {
            printf("Element found at index %d\n", mid);
            found = 1;
            break;
        } else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (!found)
        printf("Element not found\n");

    return 0;
}
