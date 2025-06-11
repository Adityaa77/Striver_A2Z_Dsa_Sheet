#include <iostream>
#include <vector>
using namespace std;

// Problem: Rearrange Array Elements by Sign
// Leetcode: https://leetcode.com/problems/rearrange-array-elements-by-sign/

// ✅ Brute Force Approach:
// 1. Separate positive and negative numbers.
// 2. Merge them alternatively into the result array.
class BruteSolution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positiveNum;
        vector<int> negativeNum;
        int k = 0, n = 0;

        // Separate positive and negative numbers
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                negativeNum.push_back(nums[i]);
                k++;
            } else if (nums[i] > 0) {
                positiveNum.push_back(nums[i]);
                n++;
            }
        }

        // Alternate merging back to nums
        k = 0; n = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (j % 2 == 0) {
                nums[j] = positiveNum[k++];
            } else {
                nums[j] = negativeNum[n++];
            }
        }

        return nums;
    }
};

// ✅ Optimized Approach:
// 1. Use one result array.
// 2. Place positive at even indices and negative at odd indices directly.
class OptimizedSolution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int p = 0, ne = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                result[ne] = nums[i];
                ne += 2;
            } else {
                result[p] = nums[i];
                p += 2;
            }
        }

        return result;
    }
};
