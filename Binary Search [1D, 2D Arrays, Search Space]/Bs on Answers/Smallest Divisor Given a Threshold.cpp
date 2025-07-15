// ✅ Problem: Smallest Divisor Given a Threshold
// ✅ Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// ✅ Level: Medium
// ✅ Tag: Binary Search on Answer
// ✅ Input: nums = [1,2,5,9], threshold = 6
// ✅ Output: 5 (because 1/5 + 2/5 + 5/5 + 9/5 = 1 + 1 + 1 + 2 = 5 ≤ 6)

// ----------------------------------------
// 🧪 Brute Force Approach
// Time Complexity: O(N * max_element)
// Space: O(1)
// ----------------------------------------

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxVal = *max_element(nums.begin(), nums.end());

        for (int divisor = 1; divisor <= maxVal; divisor++) {
            int sum = 0;
            for (int num : nums) {
                sum += (num + divisor - 1) / divisor;  // ceil division
            }
            if (sum <= threshold) return divisor;
        }

        return maxVal;
    }
};

// ----------------------------------------
// ✅ Optimal Binary Search Approach
// Time Complexity: O(N * log(max_element))
// Space: O(1)
// ----------------------------------------

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        // Quick edge case optimization
        if (n == threshold) return right;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int sum = 0;

            for (int i = 0; i < n; ++i) {
                sum += (nums[i] + mid - 1) / mid;  // ceil(nums[i]/mid)
            }

            if (sum > threshold) {
                left = mid + 1;  // Need bigger divisor
            } else {
                right = mid;     // Try smaller one
            }
        }

        return left;
    }
};
