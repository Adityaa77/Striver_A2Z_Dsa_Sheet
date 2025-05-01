// LeetCode Problem: 75. Sort Colors
// Brute-force approach using selection sort style
// Time Complexity: O(n^2), Space Complexity: O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        // Outer loop selects one element at a time
        for(int i = 0; i < n; i++) {
            // Inner loop compares the selected element with the rest
            for(int j = i + 1; j < n; j++) {
                // Swap if the current element is greater than the next one
                if(nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                }
            }
        }
    }
};
