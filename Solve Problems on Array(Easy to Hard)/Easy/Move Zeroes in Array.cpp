// Leetcode 283. Move Zeroes
// Difficulty: Easy
// https://leetcode.com/problems/move-zeroes/

// Time Complexity: O(n) - we traverse the array once or twice in worst case
// Space Complexity: O(1) - in-place operation, no extra array used

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;

        // Step 1: Find the index of the first zero
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                j = i; // Save the position of the first zero
                break;
            }
        }

        // If no zero found, array is already fine, so return
        if (j == -1) return;

        // Step 2: From the next index after j, check for non-zero elements
        for (int i = j + 1; i < nums.size(); i++) {
            if (nums[i] != 0) {
                // Swap the non-zero element with the zero at index j
                swap(nums[j], nums[i]);
                j++; // Move j to next zero position
            }
        }
    }
};
