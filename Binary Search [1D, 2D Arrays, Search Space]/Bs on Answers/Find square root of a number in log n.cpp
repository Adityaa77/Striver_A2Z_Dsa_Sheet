// -------------------------------------------
// 🔹 Brute Force Approach
// Time Complexity: O(√x)
// Space Complexity: O(1)
// -------------------------------------------
class BruteSolution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        for (int i = 1; i <= x; i++) {
            long long sq = 1LL * i * i;
            if (sq == x) return i;
            if (sq > x) return i - 1;
        }

        return 0; // Should never reach here for valid input
    }
};

// -------------------------------------------
// 🔹 Optimal Approach - Binary Search
// Time Complexity: O(log x)
// Space Complexity: O(1)
// -------------------------------------------
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int left = 0;
        int right = x;
        int ans = -1;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long val = mid * mid;

            if (val == x) return mid;

            if (val < x) {
                ans = mid;         // Store as a possible answer
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans; // Floor of sqrt(x)
    }
};
