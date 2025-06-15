// ✅ Problem: Subarray Sum Equals K
// 🔗 Leetcode: https://leetcode.com/problems/subarray-sum-equals-k/

// 🧠 Approach 1: Brute Force - Check all subarrays
// 🔍 Time: O(n^2) | Space: O(1)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                sum += nums[j];
                if(sum == k) cnt++;
            }
            sum = 0; // reset sum for next starting index
        }
        return cnt;
    }
};

// ✅ Optimal Approach: Prefix Sum + HashMap (Subarray Sum Optimized)
// 💡 Idea: Use a running sum and map to track how many times a particular prefix sum has occurred
// 🔍 Time: O(n) | Space: O(n)

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int, int> mpp; // stores (prefixSum, frequency)
        mpp[0] = 1; // to handle case when subarray itself equals k

        int presum = 0, cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            presum += arr[i]; // calculate running sum
            cnt += mpp[presum - k]; // check if there's a prefix that makes current sum - k
            mpp[presum]++; // store the current prefix sum
        }
        return cnt;
    }
};
