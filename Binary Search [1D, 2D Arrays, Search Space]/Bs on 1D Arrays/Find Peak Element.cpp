// 🔍 Problem: Find Peak Element
// 🧠 Link: https://leetcode.com/problems/find-peak-element/
// 💡 Concept: Binary Search OR Linear Search
// 📦 Constraints: Peak element always exists. O(log n) expected.

class Solution {
public:

    // 🥉 Brute Force Approach:
    // 🔁 Check all elements and their neighbors to find a peak.
    // ⏱️ Time: O(n), 📦 Space: O(1)
    int findPeakElementBrute(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        for (int i = 0; i < n; i++) {
            bool leftCheck = (i == 0 || nums[i] > nums[i - 1]);
            bool rightCheck = (i == n - 1 || nums[i] > nums[i + 1]);
            if (leftCheck && rightCheck) return i;
        }
        return -1; // won't reach here due to guaranteed peak
    }

    // ⚡ Optimal Binary Search Approach:
    // 💡 At least one peak exists due to array structure.
    // ⏱️ Time: O(log n), 📦 Space: O(1)
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int mid = (left + right) / 2;

            // if mid > next → descending, peak is on left
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            }
            // else → ascending, peak is on right
            else {
                left = mid + 1;
            }
        }

        // left == right → peak
        return left;
    }
};
