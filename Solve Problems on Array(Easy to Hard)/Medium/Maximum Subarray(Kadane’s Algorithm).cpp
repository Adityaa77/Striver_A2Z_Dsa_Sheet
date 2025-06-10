// Leetcode Problem: Maximum Subarray
// Difficulty: Medium
// Problem Link: https://leetcode.com/problems/maximum-subarray/

// Approach:
// Kadane’s Algorithm: Iterate through the array and keep track of the maximum subarray sum 
// ending at the current index. If the running sum becomes negative, reset it to 0.
// This greedy approach ensures we always keep the best local sum which can become the best global sum.

// Time Complexity: O(n) - Single pass through the array
// Space Complexity: O(1) - No extra space used

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;                   // Running sum of subarray
        int maxi = INT_MIN;            // Store the maximum sum encountered

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];            // Add current element to the running sum
            maxi = max(sum, maxi);     // Update the maximum sum if current sum is greater

            if(sum < 0) sum = 0;       // If sum becomes negative, reset it to 0
        }

        return maxi;                   // Return the maximum subarray sum
    }
};

