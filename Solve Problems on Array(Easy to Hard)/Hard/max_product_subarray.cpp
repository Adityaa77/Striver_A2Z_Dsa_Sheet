// Leetcode 152: Maximum Product Subarray
// Problem Link: https://leetcode.com/problems/maximum-product-subarray/
// ✅ Tag: Arrays | Subarrays | Product | Kadane's Variant

/*  
------------------------------------------------
🧠 Problem Summary:
Find the contiguous subarray within an array (containing at least one number)
which has the largest product.

Examples:
Input: [2,3,-2,4] → Output: 6 (subarray [2,3])
Input: [-2,0,-1]  → Output: 0
------------------------------------------------
*/

// 🔴 Brute Force Approach
// Time: O(n^2), Space: O(1)

class SolutionBrute {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxprod = nums[0];  // Start with first element

        for (int i = 0; i < n; i++) {
            int currProd = 1;
            for (int j = i; j < n; j++) {
                currProd *= nums[j];
                maxprod = max(maxprod, currProd);
            }
        }

        return maxprod;
    }
};

// ✅ Optimal Approach (Prefix & Suffix Product)
// Time: O(n), Space: O(1)
// Handles negatives by scanning both directions

class SolutionOptimal {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre = 1, suf = 1;
        int maxprod = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (pre == 0) pre = 1;
            if (suf == 0) suf = 1;

            pre *= nums[i];            // prefix from left
            suf *= nums[n - 1 - i];    // suffix from right

            maxprod = max({maxprod, pre, suf});
        }

        return maxprod;
    }
};

/*
------------------------------------------------
🧠 Notes for Revision:
- Brute: Try all subarrays, track max product.
- Optimal: Prefix-Suffix avoids resetting subarrays unnecessarily.
- Zeros reset product, so we re-initialize pre/suf when 0 is hit.
- Handles multiple negatives (e.g., [-2, -3, -4]) by scanning from both ends.
------------------------------------------------
*/
