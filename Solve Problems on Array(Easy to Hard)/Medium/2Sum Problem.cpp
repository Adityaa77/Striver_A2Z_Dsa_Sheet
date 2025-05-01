//  Problem: Two Sum (LeetCode 1)
//  Approach: Brute Force
//  Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Iterate through each element in the array
        for (int i = 0; i < nums.size(); i++) {
            // Check for every other element after the current one
            for (int j = i + 1; j < nums.size(); j++) {
                // If the two numbers add up to the target, return their indices
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        // Return empty vector if no such pair is found
        return {};
    }
};
