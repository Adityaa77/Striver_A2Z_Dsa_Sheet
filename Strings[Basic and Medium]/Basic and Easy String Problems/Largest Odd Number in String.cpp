// 🔗 Leetcode Problem: 1903. Largest Odd Number in String
// 🌟 Problem Link: https://leetcode.com/problems/largest-odd-number-in-string/
// 🧠 Objective: Return the largest-valued odd number (as a string) from a given numeric string.
// 🚫 Note: The number may be large, so avoid converting to integers (overflow risk).



// ------------------------------------------------------------------
// 🚀 Optimal Approach:
// 👉 Traverse from the end, return the first prefix that ends at an odd digit.
// ✅ Efficient and handles large inputs.
// ⏱️ Time Complexity: O(n)
// 🗃️ Space Complexity: O(1)

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                return num.substr(0, i + 1); // Return prefix ending at first odd digit from end
            }
        }
        return ""; // No odd digits found
    }
};
