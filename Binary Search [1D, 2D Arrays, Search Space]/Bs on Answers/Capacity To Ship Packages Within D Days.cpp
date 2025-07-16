// Problem: Capacity To Ship Packages Within D Days
// Leetcode Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Difficulty: Medium
// Tags: Binary Search on Answer, Greedy

/*
🔍 Problem Statement:
You're given an array `weights` representing the weight of packages in order.
You must ship all packages in `D` days using a ship with a certain max capacity.
Find the minimum capacity of the ship such that all packages can be shipped in order in at most D days.

🎯 Goal: Minimize the ship's capacity such that it can deliver all weights within D days.
*/

// ✅ Optimal Solution using Binary Search on Answer
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int mincap = 0, maxcap = 0;

        // 🏗️ Determine lower and upper bounds
        for (int weight : weights) {
            mincap = max(mincap, weight); // can't be less than heaviest package
            maxcap += weight;             // worst case: ship all in 1 day
        }

        // 🔍 Binary search for minimum valid capacity
        while (mincap < maxcap) {
            int mid = mincap + (maxcap - mincap) / 2;

            int requiredDays = 1;
            int currentLoad = 0;

            for (int w : weights) {
                if (currentLoad + w > mid) {
                    requiredDays++;
                    currentLoad = 0;
                }
                currentLoad += w;
            }

            if (requiredDays > days) {
                mincap = mid + 1; // need bigger capacity
            } else {
                maxcap = mid;     // try a smaller capacity
            }
        }

        return mincap;
    }
};
