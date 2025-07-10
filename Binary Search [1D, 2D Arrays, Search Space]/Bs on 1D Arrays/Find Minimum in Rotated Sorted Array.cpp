// ✅ Problem: Find Minimum in Rotated Sorted Array (No Duplicates)
// You are given a rotated sorted array without duplicates. Find the minimum element.

// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------------------
// ✅ Brute Force Approach
// Traverse all elements and track the minimum value.

// 🔍 Time Complexity: O(n)
// 🔍 Space Complexity: O(1)

class BruteForceSolution {
public:
    int findMin(vector<int>& nums) {
        int minVal = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            minVal = min(minVal, nums[i]);
        }
        return minVal;
    }
};

// --------------------------------------------------------------
// ✅ Optimal Approach: Modified Binary Search
// Since the array is rotated and sorted, we can use binary search
// to find the pivot point which is the smallest element.

// 🔍 Time Complexity: O(log n)
// 🔍 Space Complexity: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int ans = INT_MAX;

        while (left <= right) {
            int mid = (left + right) / 2;

            // 🟢 Case 1: Whole segment is already sorted
            if (nums[left] <= nums[right]) {
                ans = min(ans, nums[left]);
                break;
            }

            // 🟠 Case 2: Left half is sorted
            if (nums[left] <= nums[mid]) {
                ans = min(ans, nums[left]);
                left = mid + 1;
            }

            // 🔴 Case 3: Right half is unsorted (minimum is in left part)
            else {
                ans = min(ans, nums[mid]); 
                right = mid - 1;
            }
        }

        return ans;
    }
};
