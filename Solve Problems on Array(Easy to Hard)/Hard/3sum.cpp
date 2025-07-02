// ============================================================================
// 🧠 LEETCODE 15 - 3SUM | Find all triplets in array that sum to 0
// ============================================================================
// ✅ Constraints:
//  - Must return all unique triplets [nums[i], nums[j], nums[k]] such that:
//      -> i != j != k
//      -> nums[i] + nums[j] + nums[k] == 0
//  - Answer should not contain duplicate triplets
// ============================================================================


// -------------------------
// 🥇 BRUTE FORCE - O(N^3 log N)
// -------------------------
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;  // set to store unique triplets
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());  // sort to normalize
                        st.insert(triplet);  // insert unique
                    }
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};


// -------------------------
// 🥈 BETTER - O(N^2 * log M) | Using HashSet
// -------------------------
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            set<int> hashset;  // used to find the 3rd element

            for (int j = i + 1; j < n; j++) {
                int third = -(nums[i] + nums[j]);

                if (hashset.find(third) != hashset.end()) {//very imp for knowing if the hashset has the element
                    vector<int> triplet = {nums[i], nums[j], third};
                    sort(triplet.begin(), triplet.end());
                    st.insert(triplet);  // set handles uniqueness
                }

                hashset.insert(nums[j]);
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};


// -------------------------
// 🥇 OPTIMAL - O(N^2) | Two Pointers
// -------------------------
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());  // sort the array

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicates

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    // found a valid triplet
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // skip duplicates
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }

        return ans;
    }
};
