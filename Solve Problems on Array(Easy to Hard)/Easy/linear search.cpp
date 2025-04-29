// 🚀 Problem: Linear Search in Array
// 📝 Problem Link: https://takeuforward.org/plus/dsa/problems/linear-search

// ✅ Time Complexity: O(n), where n is the number of elements in the array
// ✅ Space Complexity: O(1), no extra space used

#include <iostream>
#include <vector>
using namespace std;

// Linear search function
bool linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        // Check each element one by one
        if (arr[i] == target) {
            return true; // Found the target
        }
    }
    return false; // Target not found
}

int main() {
    // Sample input
    vector<int> arr = {1, 3, 5, 7, 9};
    int target = 5;

    // Call the function and print result
    if (linearSearch(arr, target)) {
        cout << "Element found!" << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    return 0;
}
