// ✅ Problem: Find the nth root of an integer m
// Example: If n = 3 and m = 27 → return 3 (since 3^3 = 27)
// Return -1 if no integer root exists

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /* ---------------------------------------------------------------------------------
    🔸 Brute Force Approach
    - Try every number i from 1 to m
    - Check if i^n == m
    - If found, return i
    - If not found after the loop, return -1

    ✅ Time: O(m * n)  → For each i, multiply i by itself n times
    ✅ Space: O(1)
    --------------------------------------------------------------------------------- */
    int nthRootBrute(int n, int m) {
        for (int i = 1; i <= m; i++) {
            long long result = 1;
            for (int j = 0; j < n; j++) {
                result *= i;
                if (result > m) break;
            }

            if (result == m) return i;
        }
        return -1;
    }

    /* ---------------------------------------------------------------------------------
    🔹 Optimal Approach: Binary Search on Answer
    - The answer lies between 1 and m.
    - Use binary search to efficiently find the integer such that mid^n == m
    - Use long long to avoid overflow during power calculation

    ✅ Time: O(log m * n)
    ✅ Space: O(1)
    --------------------------------------------------------------------------------- */
    int nthRoot(int n, int m) {
        if (n == 1) return m;

        int left = 1, right = m;
        int answer = -1;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long result = 1;

            // Compute mid^n using loop to avoid using pow()
            for (int i = 0; i < n; i++) {
                result *= mid;
                if (result > m) break;
            }

            if (result == m) {
                answer = mid;
                break;  // Exact integer root found
            }
            else if (result > m) {
                right = mid - 1;  // Root is smaller
            }
            else {
                left = mid + 1;   // Root is larger
            }
        }

        return answer;
    }
};
