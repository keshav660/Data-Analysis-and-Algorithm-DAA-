#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if key is present at mid
        if (arr[mid] == key) {
            return mid;
        }
        
        // If key is greater, ignore left half
        if (arr[mid] < key) {
            left = mid + 1;
        }
        // If key is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }
    return -1; // Element not found
}

int main() {
    int n, key;
    cout << "Enter the number of elements (sorted): ";
    cin >> n;
    int arr[n];
    
    cout << "Enter the sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter the element to search: ";
    cin >> key;
    
    int result = binarySearch(arr, 0, n - 1, key);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }
    
    return 0;
}
