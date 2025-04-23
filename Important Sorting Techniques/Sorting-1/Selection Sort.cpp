#include <bits/stdc++.h>
using namespace std;

/*
    Selection Sort Algorithm

    Steps:
    - Traverse the array from 0 to n-1.
    - For each position i, find the minimum element in the subarray from i to n-1.
    - Swap the found minimum with the current element at position i.
*/

void selectionSort(int arr[], int n) {
    for (int i = 0; i <=n - 2; i++) {
        int mini = i;

        // Find the index of the minimum element in the remaining unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }

        // Swap the current element with the found minimum
        swap(arr[i], arr[mini]);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

