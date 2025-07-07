// 📌 Problem: Search in Rotated Sorted Array
// Given a rotated sorted array and a target, find the index of the target if present, else return -1.
// You must solve it in O(log n) time.

// ✅ Approach 1: Brute Force
// Simply iterate through the array and check each element.

// 🔍 Time Complexity: O(n)
// 🔍 Space Complexity: O(1)

class SolutionBrute {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == target) return i;
        }
        return -1;
    }
};

// ✅ Approach 2: Binary Search (Optimized for Rotated Sorted Array)
// Use binary search by identifying which half of the array is sorted.
// Then decide whether to search in the left or right half accordingly.

// 🔍 Time Complexity: O(log n)
// 🔍 Space Complexity: O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            // 🎯 If mid is the target, return its index
            if (nums[mid] == target) return mid;

            // ✅ Check if the left half is sorted
            if (nums[left] <= nums[mid]) {
                // Check if target lies within the sorted left half
                if (nums[left] <= target && target <= nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;  // 
                }
            }
            // ✅ Otherwise, the right half must be sorted
            else {
                if (nums[mid] <= target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1; // 🔁 Not found
    }
};
