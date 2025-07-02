// ============================================================================
// 🧠 LEETCODE 18 - 4SUM | Find all unique quadruplets (a+b+c+d = target)
// ============================================================================
// ✅ Constraints:
//  - Return all unique quadruplets [nums[i], nums[j], nums[k], nums[l]] such that:
//      -> i != j != k != l
//      -> nums[i] + nums[j] + nums[k] + nums[l] == target
//  - Cannot contain duplicate quadruplets
// ============================================================================


// -------------------------
// 🥉 BRUTE FORCE - O(N^4 * log M)
// -------------------------
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];
                        if (sum == target) {
                            vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};
                            sort(quad.begin(), quad.end());
                            st.insert(quad);
                        }
                    }
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};


// -------------------------
// 🥈 BETTER - O(N^3 log M) using HashSet
// -------------------------
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                set<int> hashset;

                for (int k = j + 1; k < n; k++) {
                    long long fourth = (long long)target - nums[i] - nums[j] - nums[k];
                    if (hashset.find(fourth) != hashset.end()) {
                        vector<int> quad = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(quad.begin(), quad.end());
                        st.insert(quad);
                    }

                    hashset.insert(nums[k]);
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};


// -------------------------
// 🥇 OPTIMAL - O(N^3) | Two Pointers after sorting
// -------------------------
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicates

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // skip duplicates

                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;

                        while (k < l && nums[k] == nums[k - 1]) k++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    }
                    else if (sum < target) {
                        k++;
                    }
                    else {
                        l--;
                    }
                }
            }
        }

        return ans;
    }
};
