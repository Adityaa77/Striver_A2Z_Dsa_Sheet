
// 📌 Problem: Valid Parentheses
// 🔗 LeetCode: https://leetcode.com/problems/valid-parentheses/
//
// 📝 Problem Statement:
//   Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
//   determine if the input string is valid.
//
//   An input string is valid if:
//     1. Open brackets must be closed by the same type of brackets.
//     2. Open brackets must be closed in the correct order.
//     3. Every closing bracket has a corresponding opening bracket.
//
// Example 1:
//   Input: s = "()"
//   Output: true
//
// Example 2:
//   Input: s = "()[]{}"
//   Output: true
//
// Example 3:
//   Input: s = "(]"
//   Output: false
//
// 🧠 Approach (Stack):
//   - Traverse the string character by character.
//   - If it's an opening bracket, push onto stack.
//   - If it's a closing bracket:
//       * Check if stack is empty (invalid if empty).
//       * Check if top of stack has the matching opening bracket.
//       * If mismatch, return false.
//       * If match, pop the top element.
//   - After traversal, if stack is empty → return true (all matched).
//
// ⏱ Time Complexity: O(n)  (each character is processed once)
// 💾 Space Complexity: O(n)  (stack can hold up to n characters)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // stack to store opening brackets

        for (auto i : s) {
            // Case 1: Opening bracket → push to stack
            if (i == '(' || i == '{' || i == '[') {
                st.push(i);
            }
            // Case 2: Closing bracket → check stack
            else {
                if (st.empty() || 
                   (st.top() == '(' && i != ')') || 
                   (st.top() == '{' && i != '}') || 
                   (st.top() == '[' && i != ']')) {
                    return false;
                }
                st.pop(); // valid match, remove from stack
            }
        }

        // Stack should be empty if all brackets matched
        return st.empty();
    }
};

/*
Example usage:

int main() {
    Solution sol;
    cout << sol.isValid("()") << endl;      // true
    cout << sol.isValid("()[]{}") << endl;  // true
    cout << sol.isValid("(]") << endl;      // false
    cout << sol.isValid("([)]") << endl;    // false
    cout << sol.isValid("{[]}") << endl;    // true
    return 0;
}
*/
