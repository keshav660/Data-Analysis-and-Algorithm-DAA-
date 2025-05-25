#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Element not found
}

int main() {
    int n, key;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter the element to search: ";
    cin >> key;
    
    int result = linearSearch(arr, n, key);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }
    
    return 0;
}
