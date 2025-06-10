#include <iostream>
#include <vector>
using namespace std;

// Function to print the subarray with the maximum sum
int maxSubArraySum(vector<int>& nums) {
    int maxSum = nums[0];      // Store the maximum subarray sum
    int currSum = 0;           // Running sum of the current subarray
    int start = 0, end = 0;    // To store start and end indices of max subarray
    int tempStart = 0;         // Temporary start index when resetting currSum

    for (int i = 0; i < nums.size(); i++) {
        currSum += nums[i];

        // If we found a new max, update start and end indices
        if (currSum > maxSum) {
            maxSum = currSum;
            start = tempStart;
            end = i;
        }

        // If current sum becomes negative, reset it
        if (currSum < 0) {
            currSum = 0;
            tempStart = i + 1;  // Next index could be a potential new subarray start
        }
    }

    // Print the maximum subarray
    cout << "Subarray with maximum sum: ";
    for (int i = start; i <= end; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "Maximum Subarray Sum: " << maxSum << endl;

    return maxSum;
}

int main() {
    vector<int> nums = {1, -2, 3, 4, -5, 8};  // Example input
    maxSubArraySum(nums);
    return 0;
}
