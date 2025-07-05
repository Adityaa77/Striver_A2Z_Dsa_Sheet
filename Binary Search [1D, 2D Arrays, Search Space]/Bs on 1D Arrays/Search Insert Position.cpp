// 🔍 Problem: Search Insert Position
// Given a sorted array of distinct integers and a target value, return the index if the target is found.
// If not, return the index where it would be if it were inserted in order.

// ✅ Approach 1: Brute Force
// Traverse the array, count how many elements are smaller than the target.
// If target is found, return its index. Otherwise, return the count (insert position).

// ⏱️ Time Complexity: O(n)
// 🛠️ Space Complexity: O(1)

class SolutionBrute {
public:
    int searchInsert(vector<int>& nums, int target) {
        int num = 0;  // stores potential insert position
        for (int i = 0; i < nums.size(); i++) {
            if (target > nums[i]) {
                num++;
            }
            if (target == nums[i]) {
                return i;  // target found
            }
        }
        return num;  // target not found, return insert position
    }
};

// ✅ Approach 2: Optimal Binary Search
// Use binary search to find the position where the target fits in sorted order.

// ⏱️ Time Complexity: O(log n)
// 🛠️ Space Complexity: O(1)

class SolutionOptimal {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int ans = n;  // default insert position if target is greater than all elements

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;  // target found
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                ans = mid;      // potential insert position
                right = mid - 1;
            }
        }

        return ans;
    }
};
