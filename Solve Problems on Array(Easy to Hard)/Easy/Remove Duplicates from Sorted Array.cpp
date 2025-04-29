
// LeetCode: 26. Remove Duplicates from Sorted Array
// Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;

        // Loop through the array to shift unique elements forward
        for (int i = 0; i < nums.size(); i++) {
            if (nums[j] != nums[i]) {
                nums[j + 1] = nums[i];  // Place next unique element
                j++;  // Move pointer for unique elements
            }
        }

        return j + 1; // Total count of unique elements
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
