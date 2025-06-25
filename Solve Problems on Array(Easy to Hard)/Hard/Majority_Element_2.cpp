// ✅ Problem: 229. Majority Element II
// 🔗 Link: https://leetcode.com/problems/majority-element-ii/
// 📌 Statement:
// Given an integer array nums, return all the elements that appear more than ⌊n / 3⌋ times.
// You may return the answer in any order.
// --------------------------------------------------------------------------------------
// 🧠 Constraints:
// - 1 <= nums.length <= 5 * 10^4
// - -10^9 <= nums[i] <= 10^9
// --------------------------------------------------------------------------------------

/* --------------------------------------------------------------------------------------------------
🟠 Brute Force Approach - Using Sorting
Time: O(n log n)
Space: O(1) (excluding output space)
Logic:
- Sort the array
- Count frequency of each distinct element and check if it's > n/3
-------------------------------------------------------------------------------------------------- */
class Solution {
public:
    vector<int> majorityElement_brute(vector<int>& nums) {
        int n = nums.size();
        int threshold = n / 3;
        int cnt = 1;
        vector<int> ans;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                cnt++;
            } else {
                if (cnt > threshold) {
                    ans.push_back(nums[i - 1]);
                }
                cnt = 1;
            }
        }

        // Final check for last element
        if (cnt > threshold) {
            ans.push_back(nums[n - 1]);
        }

        return ans;
    }
};

/* --------------------------------------------------------------------------------------------------
🟡 Better Approach - Using Hash Map (Frequency Count)
Time: O(n)
Space: O(n)
Logic:
- Use unordered_map to count frequency
- Push into result when frequency becomes exactly threshold (to avoid duplicates)
-------------------------------------------------------------------------------------------------- */
class Solution2 {
public:
    vector<int> majorityElement_better(vector<int>& nums) {
        int n = nums.size();
        int threshold = n / 3 + 1; // +1 to safely catch elements appearing more than n/3
        unordered_map<int, int> freq;
        vector<int> result;

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            if (freq[nums[i]] == threshold) {
                result.push_back(nums[i]);
            }
        }

        return result;
    }
};

/* --------------------------------------------------------------------------------------------------
🟢 Optimal Approach - Moore's Voting Algorithm (Extended)
Time: O(n)
Space: O(1)
Logic:
- There can be at most 2 elements with frequency > n/3
- Use two counters and two candidate variables
- 1st pass to find potential candidates
- 2nd pass to validate the actual frequencies
-------------------------------------------------------------------------------------------------- */
class Solution3 {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        // Step 1: Find candidates
        for (int num : nums) {
            if (num == el1) cnt1++;
            else if (num == el2) cnt2++;
            else if (cnt1 == 0) {
                el1 = num;
                cnt1 = 1;
            }
            else if (cnt2 == 0) {
                el2 = num;
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        // Step 2: Verify candidates
        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == el1) cnt1++;
            else if (num == el2) cnt2++;
        }

        int threshold = nums.size() / 3;
        vector<int> result;
        if (cnt1 > threshold) result.push_back(el1);
        if (cnt2 > threshold) result.push_back(el2);

        return result;
    }
};
