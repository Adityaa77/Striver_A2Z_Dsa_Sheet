#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: Next Permutation
// Leetcode: https://leetcode.com/problems/next-permutation/

// 1. Optimal STL-based one-liner (most efficient and clean)
class STLSolution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

// 2. Manual Implementation (without STL)
// Logic: 
// 1. Find first decreasing element from right
// 2. Swap it with the next greater element from right
// 3. Reverse the suffix
class ManualSolution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 2;

        // Step 1: Find the first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // Step 2: Find element just larger than nums[i] on the right
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]); // Step 3: Swap them
        }

        // Step 4: Reverse the suffix
        reverse(nums.begin() + i + 1, nums.end());
    }
};

/*
 3. Brute Force (Theoretical - not implemented)
--------------------------------------------------
- Generate all permutations using recursion (backtracking).
- Sort them, and return the one just after the given one.
- ❗ Very slow and gives TLE for large inputs.
*/
