// 🔍 Problem: Find the element that appears only once in a sorted array
// Every other element appears exactly twice
// Leetcode Link: https://leetcode.com/problems/single-element-in-a-sorted-array/

// ✅ Approach 1: Brute Force
// --------------------------------------------------
// Traverse the array and use XOR to cancel out duplicate elements
// because x ^ x = 0 and x ^ 0 = x, so all duplicates cancel out,
// and the unique one remains.

// 🔸 Time Complexity: O(n)
// 🔸 Space Complexity: O(1)

class BruteSolution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }
        return ans;
    }
};

// ✅ Approach 2: Optimal using Binary Search
// --------------------------------------------------
// Since array is sorted and all elements appear twice except one,
// we can use binary search to find the unique element efficiently.

// 🔸 Time Complexity: O(log n)
// 🔸 Space Complexity: O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        // Edge cases for array of size 1 or unique at boundaries
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        while (left <= right) {
            int mid = (left + right) / 2;

            // ✅ Check if nums[mid] is the unique element
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            // ✅ Check which side to move
            // If mid is even and nums[mid] == nums[mid + 1], unique is on the right
            // If mid is odd and nums[mid] == nums[mid - 1], unique is on the right
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1; // This line should never be reached if input is valid
    }
};
