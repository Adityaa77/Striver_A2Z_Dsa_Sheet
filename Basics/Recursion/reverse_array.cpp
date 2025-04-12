#include <iostream>
using namespace std;

// Function to reverse array using recursion
void reverse(int i, int arr[], int n) {
    if (i >= n / 2) return;
    swap(arr[i], arr[n - i - 1]);
    reverse(i + 1, arr, n);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    // Input array elements
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Call recursive reverse function
    reverse(0, arr, n);

    // Print reversed array
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}
