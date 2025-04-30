// Leetcode Problem: Missing Number
// Difficulty: Easy
// Problem Link: https://leetcode.com/problems/missing-number/
// Approach: Hashing using an auxiliary vector to mark the presence of each number from 0 to n

// Time Complexity: O(n)
// Space Complexity: O(n) — due to the extra hash array

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();  // Since one number is missing, array size is n (numbers from 0 to n)

        // Create a hash array of size n+1 and initialize all to 0
        vector<int> hashh(n + 1, 0);

        // Mark the elements that are present in nums
        for (int i = 0; i < n; i++) {
            hashh[nums[i]] = 1;
        }

        // The index with 0 in hashh is the missing number
        for (int i = 0; i <= n; i++) {
            if (hashh[i] == 0) {
                return i;
            }
        }

        // This return is just for safety; the problem guarantees a solution
        return -1;
    }
};
