#include <iostream>
using namespace std;

// 🌀 Version 1: Reverse loop style (i from n-1 to 0)
void bubblesort(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 🔁 Version 2: Normal style (i from 0 to n-1) – RECOMMENDED
void bubblesortt(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
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

    // 🔧 Use either of the bubble sort versions
    // bubblesort(arr, n);   // reverse version
    bubblesortt(arr, n);     // normal version

    // 📤 Output the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
