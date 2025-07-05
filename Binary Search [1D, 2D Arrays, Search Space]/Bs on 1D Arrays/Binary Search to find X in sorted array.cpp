// Problem: Search in a Sorted Array
// Link: https://leetcode.com/problems/binary-search/
// Given a sorted array of integers and a target value, return the index if the target is found.
// If not, return -1. You must write an algorithm with O(log n) runtime complexity.

// ✅ Brute Force Approach
// 🔍 Time Complexity: O(n)
// 🔧 Space Complexity: O(1)
// 📌 Loop through each element and compare with target
class BruteForceSolution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                index = i;
                return i; // Found target at index i
            }
        }
        return index; // Target not found
    }
};


// ✅ Optimal Approach using Binary Search
// 🔍 Time Complexity: O(log n)
// 🔧 Space Complexity: O(1)
// 📌 Use binary search since array is sorted
class OptimalSolution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left <= right) {
            // ⚠️ Safer mid to avoid overflow: left + (right - left) / 2
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;         // Target found
            else if (nums[mid] > target) right = mid - 1; // Target in left half
            else left = mid + 1;                         // Target in right half
        }

        return -1; // Target not found
    }
};

/*
🧠 Summary:
- Use brute force for understanding and small arrays.
- Use binary search for optimal performance in sorted arrays.
- Always check bounds to avoid overflow when calculating mid.
*/
