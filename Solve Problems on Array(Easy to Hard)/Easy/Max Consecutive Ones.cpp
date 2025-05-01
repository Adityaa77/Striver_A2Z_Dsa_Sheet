// LeetCode: 485. Max Consecutive Ones
// Time: O(n), Space: O(1)
// problem-https://leetcode.com/problems/max-consecutive-ones/description/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++; // increase current 1's streak
                if (count > maxCount) {
                    maxCount = count; // update max streak
                }
            } else {
                count = 0; // reset streak on 0
            }
        }

        return maxCount;
    }
};
