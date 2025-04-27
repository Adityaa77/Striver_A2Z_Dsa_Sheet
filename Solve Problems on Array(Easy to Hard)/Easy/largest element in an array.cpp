#include <bits/stdc++.h>
using namespace std;
// Problem: Find the Largest Element in an Array
// Link: N/A (User Input-based problem)
// Function to find the largest element in the array
int largestElement(vector<int>& nums) {
    int largest = nums[0];  // Initialize with the first element
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > largest) {
            largest = nums[i];
        }
    }
    return largest;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << largestElement(nums) << endl;

    return 0;
}
/*
⏳ Time Complexity: 
- O(N), where N = size of array
- We perform one pass through the array, comparing each element once.

🛢️ Space Complexity:
- O(1)
- We only use a constant amount of extra space for the variable `largest`.
*/
