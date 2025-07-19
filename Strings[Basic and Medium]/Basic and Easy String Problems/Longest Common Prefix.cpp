// 🔗 Leetcode Problem: 14. Longest Common Prefix (https://leetcode.com/problems/longest-common-prefix/)
// 🧠 Approach: Sort the array and compare the first and last strings
// ⏱️ Time Complexity: O(N * logN + M) — N = number of strings, M = min length of first/last string
// 🗃️ Space Complexity: O(1) — ignoring sort space
// ✅ Status: Optimal for most practical use cases

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Edge case: empty input
        if (strs.empty()) return "";

        // Sort strings to bring similar prefixes closer
        sort(strs.begin(), strs.end());

        // Compare the first and last strings only
        string first = strs.front();
        string last = strs.back();
        string result = "";

        // Build the common prefix
        for (int i = 0; i < first.size(); i++) {
            if (first[i] == last[i]) {
                result += first[i];
            } else {
                break;
            }
        }

        return result;
    }
};

// 🧠 Approach: Vertical scanning - check each char column-wise
// ⏱️ Time Complexity: O(N * M)
// 🗃️ Space Complexity: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        for (int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != c)
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};
