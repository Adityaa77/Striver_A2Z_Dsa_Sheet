// Leetcode: 189. Rotate Array
// https://leetcode.com/problems/rotate-array/
// Difficulty: Medium
//
// Time Complexity: O(n)
// Space Complexity: O(n) — extra space for temporary vector

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 1) return;

        k = k % nums.size();  // Handle cases where k > nums.size()
        vector<int> number;
        int n = nums.size() - k;

        // Add the last k elements to the front
        for (int i = n; i < nums.size(); i++) {
            number.push_back(nums[i]);
        }

        // Add the first n elements after
        for (int j = 0; j < n; j++) {
            number.push_back(nums[j]);
        }

        nums = number;  // Update the original array
    }
};
