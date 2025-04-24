#include <iostream>
using namespace std;

// 📌 Insertion Sort Algorithm
// Time Complexity: O(N^2) – Worst & Average case
// Best Case: O(N) when array is already sorted

void insertionsort(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        // 🧠 Push current element to its correct position in the sorted part
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insertionsort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
