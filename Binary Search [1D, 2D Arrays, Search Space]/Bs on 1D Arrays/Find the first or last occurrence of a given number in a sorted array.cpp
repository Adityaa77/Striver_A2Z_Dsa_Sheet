// ✅ Problem: Find First and Last Position of Element in Sorted Array
// Given an array of integers nums sorted in non-decreasing order, find the starting 
// and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// ----------------------------------------------------------------------------------
// ✅ Brute Force Approach
// Time Complexity: O(n)
// Space Complexity: O(1) (ignoring output space)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> arr;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                // If both start and end index already added
                if (arr.size() == 2) {
                    // Keep updating the last index to get the furthest right position
                    arr.back() = max(arr[arr.size() - 1], i);
                }
                // First occurrence
                else {
                    arr.push_back(i);
                }
            }
        }

        // Handle case when target not found
        if (arr.size() == 0) arr = {-1, -1};

        // If only one occurrence found, duplicate it
        if (arr.size() == 1) arr.push_back(arr[0]);

        return arr;
    }
};

// ----------------------------------------------------------------------------------
// ✅ Optimal Approach (Using Binary Search Twice)
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2, -1); // Initialize answer as [-1, -1]

        // First Binary Search to find first occurrence
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                ans[0] = mid;     // Update first occurrence
                right = mid - 1;  // Move left to find earlier occurrence
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Second Binary Search to find last occurrence
        left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                ans[1] = mid;     // Update last occurrence
                left = mid + 1;   // Move right to find later occurrence
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
