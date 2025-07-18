// ✅ Problem: Minimum Number of Days to Make m Bouquets
// Leetcode: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Tags: Binary Search on Answer, Greedy, Array

#include <bits/stdc++.h>
using namespace std;

/*
🧠 Problem Summary:
- You are given an array `bloomDay[]` of size `n`.
- Each element represents the day a flower will bloom.
- You need to make `m` bouquets.
- Each bouquet must contain `k` **adjacent** bloomed flowers.
- Return the **minimum number of days** required to make all bouquets.
- Return `-1` if it's not possible.
*/

/* --------------------------------------------------------------------------------------
🔸 Brute Force Approach:
- Try every day from min(bloomDay) to max(bloomDay).
- For each day, simulate the process:
   → Count how many bouquets you can make using only bloomed flowers (<= current day).
   → If number of bouquets ≥ m, return that day.
- ❌ Time Complexity: O((max_day - min_day) * n) → Will TLE for large ranges
---------------------------------------------------------------------------------------- */

class Solution {
public:
    int minDaysBrute(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n) return -1;  // Not enough flowers in total

        int minDay = *min_element(bloomDay.begin(), bloomDay.end());
        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());

        for (int day = minDay; day <= maxDay; day++) {
            int bouquets = 0, flowers = 0;

            for (int b : bloomDay) {
                if (b <= day) {
                    flowers++;
                    if (flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
            }

            if (bouquets >= m) return day;  // First day when it's possible
        }

        return -1;  // Not possible on any day
    }

    /* --------------------------------------------------------------------------------------
    🔹 Optimized Approach: Binary Search on Answer + Greedy Bouquet Check
    - The minimum number of days lies between min(bloomDay) to max(bloomDay).
    - Do a binary search on this range:
        → For each mid = day, check if we can make m bouquets using only flowers that bloom ≤ mid.
    - If yes: Try smaller days (right = mid - 1).
    - If no: Try bigger days (left = mid + 1).
    - Uses Greedy inside each mid check to count adjacent flowers.
    - ✅ Time: O(n * log(max_day - min_day))
    - ✅ Space: O(1)
    ---------------------------------------------------------------------------------------- */

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n) return -1;  // Not enough flowers

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int bouquet = 0;
            int flowers = 0;

            for (int days : bloomDay) {
                if (days <= mid) {
                    flowers++;
                    if (flowers == k) {
                        bouquet++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
            }

            if (bouquet >= m) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
};
