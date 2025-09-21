/*
 * Problem: Sum of Subarray Ranges
 * Platform: LeetCode
 *
 * Description:
 *   Given an integer array nums, the range of a subarray is the 
 *   difference between the maximum and minimum element in that subarray.
 *   Return the sum of all subarray ranges of nums.
 *
 * Example:
 *   Input: nums = [1,2,3]
 *   Output: 4
 *   Explanation:
 *     Subarrays: [1], [2], [3], [1,2], [2,3], [1,2,3]
 *     Ranges:    0   + 0   + 0   + (2-1) + (3-2) + (3-1) = 4
 *
 * Approaches:
 *   1. Brute Force
 *   2. Optimized (Monotonic Stack) – TODO
 */

/* ---------------- BRUTE FORCE ----------------
 * Idea:
 *   - For each subarray [i..j], compute min and max.
 *   - Add (max - min) to the answer.
 *
 * Time Complexity: O(n^2)
 *   - Outer loop fixes start index i.
 *   - Inner loop extends to j, updating min and max in O(1).
 *   - Total O(n^2).
 *
 * Space Complexity: O(1)
 *   - Only variables for min, max, and sum.
 */
class SolutionBrute {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int mn = nums[i], mx = nums[i];
            for (int j = i; j < n; j++) {
                mn = min(mn, nums[j]);
                mx = max(mx, nums[j]);
                sum += (mx - mn);
            }
        }
        
        return sum;
    }
};

/* ---------------- OPTIMIZED (MONOTONIC STACK) ----------------
 * TODO:
 *   - Use stacks to count how many subarrays each element contributes to
 *     as maximum and as minimum.
 *   - Sum contributions for all elements.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // TODO: Implement optimized approach
        return 0;
    }
};
