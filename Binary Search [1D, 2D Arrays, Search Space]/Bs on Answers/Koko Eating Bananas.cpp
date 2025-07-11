// ✅ Problem: Koko Eating Bananas
// 🔗 Link: https://leetcode.com/problems/koko-eating-bananas/

// 🧠 Problem Statement:
// Koko loves to eat bananas. There are `piles[]` where each pile[i] represents the number of bananas.
// Koko can eat at most K bananas per hour. Find the minimum value of K such that she can eat all bananas in `h` hours.

// 🍌 Rules:
// - She eats from only one pile per hour.
// - If a pile has less than K bananas, she eats the whole pile.
// - You must find the minimum K such that she finishes all in ≤ h hours.

// 🔒 Constraints:
// - 1 <= piles.length <= 10^4
// - 1 <= piles[i] <= 10^9
// - 1 <= h <= 10^9

// --------------------------------------------------------
// 🧪 Brute Force Approach (TLE for large test cases)
// --------------------------------------------------------
/*
   Try every possible eating speed from 1 to max(piles)
   and check how many hours it takes.
   The first speed for which total hours ≤ h is the answer.
   Time: O(max(piles) * N)
*/
int bruteMinEatingSpeed(vector<int>& piles, int h) {
    int maxBananas = *max_element(piles.begin(), piles.end());
    for (int k = 1; k <= maxBananas; k++) {
        long long hours = 0;
        for (int p : piles) {
            hours += (p + k - 1) / k; // ceil(p/k)
        }
        if (hours <= h) return k;
    }
    return maxBananas; // Worst-case return
}

// --------------------------------------------------------
// ✅ Optimal Approach using Binary Search
// --------------------------------------------------------
/*
   Search space: [1, max(piles)]
   - For a mid speed, calculate total hours.
   - If hours ≤ h: valid answer, try smaller speed.
   - If hours > h: need higher speed.
   Time: O(N * log(max(piles)))
*/
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long hours = 0;

            for (int p : piles) {
                hours += (p + mid - 1) / mid; // ceil(p/mid)
            }

            if (hours <= h) {
                ans = mid;        // Possible answer, but check for smaller k
                right = mid - 1;
            } else {
                left = mid + 1;   // Not enough speed, increase it
            }
        }

        return ans;
    }
};
