#include <bits/stdc++.h>
using namespace std;

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

