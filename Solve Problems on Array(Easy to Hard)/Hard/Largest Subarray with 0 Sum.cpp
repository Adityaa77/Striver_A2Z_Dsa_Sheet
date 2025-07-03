// 📌 Problem: Largest Subarray with 0 Sum
// ✅ Status: Solved using Brute-force & Optimal
// 🔗 GFG Link: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// 📘 Notes: Revise prefix sum & hashmap logic carefully for the optimal approach.


// ✅ Brute-force Approach
// Time Complexity: O(N^2)
// Space Complexity: O(1)
class Solution {
public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum == 0) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};


// 🚀 Optimal Approach (Prefix Sum + Hashmap)
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mpp;  // stores prefixSum -> index
        int sum = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (sum == 0) {
                ans = i + 1;  // whole subarray from 0 to i
            }
            else if (mpp.find(sum) != mpp.end()) {
                ans = max(ans, i - mpp[sum]);
            }
            else {
                mpp[sum] = i;  // store first occurrence only
            }
        }

        return ans;
    }
};
