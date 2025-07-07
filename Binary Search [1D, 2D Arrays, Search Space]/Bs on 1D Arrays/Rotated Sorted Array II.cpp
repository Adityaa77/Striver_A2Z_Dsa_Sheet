// 📌 Problem: Search in Rotated Sorted Array II (with duplicates)
// LeetCode: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// You are given an integer array 'nums' which may contain duplicates and is rotated.
// Return true if 'target' exists in the array.

// ✅ Approach 1: Brute Force
// Traverse the entire array and check each element.

// 🔍 Time Complexity: O(n)
// 🔍 Space Complexity: O(1)

class SolutionBrute {
public:
    bool search(vector<int>& nums, int target) {
        for (int num : nums) {
            if (num == target) return true;
        }
        return false;
    }
};


// ✅ Approach 2: Optimized Binary Search (Handles Duplicates)
// This approach uses binary search while also handling duplicates (which can break standard binary logic).

// 🔍 Time Complexity: O(log n) in best case, O(n) in worst case due to duplicates
// 🔍 Space Complexity: O(1)

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            // 🎯 Found the target
            if (nums[mid] == target) return true;

            // ⚠️ Skip duplicates on both ends
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
                continue;
            }

            // ✅ Left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target <= nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            // ✅ Right half is sorted
            else {
                if (nums[mid] <= target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        // ❌ Not found
        return false;
    }
};
