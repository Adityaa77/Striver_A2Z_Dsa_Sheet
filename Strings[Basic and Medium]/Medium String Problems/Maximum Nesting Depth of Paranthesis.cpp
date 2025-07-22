// 🔗 Leetcode Problem: 1614. Maximum Nesting Depth of the Parentheses
// 🧠 Approach: Count open parentheses depth using a single traversal
// ⏱️ Time Complexity: O(N)
// 🗃️ Space Complexity: O(1)
// ✅ Status: Optimal

class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int cnt = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                cnt++;
                count = max(cnt, count);
            }
            else if (s[i] == ')') cnt--;
        }

        return count;
    }
};
