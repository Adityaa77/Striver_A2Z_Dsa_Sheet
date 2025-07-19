// Leetcode 1021. Remove Outermost Parentheses
// Link: https://leetcode.com/problems/remove-outermost-parentheses/


/*
----------------------------------
✅ Brute Force - Using Stack
----------------------------------
Time Complexity: O(n)  
Space Complexity: O(n)
*/
string removeOuterParentheses_brute(string s) {
    stack<char> st;
    string res = "";
    for (char c : s) {
        if (c == '(') {
            if (!st.empty()) res += c;
            st.push(c);
        } else {
            st.pop();
            if (!st.empty()) res += c;
        }
    }
    return res;
}


/*
----------------------------------
✅ Optimal - Cleanest Counter Logic
----------------------------------
Time Complexity: O(n)  
Space Complexity: O(1)
*/
string removeOuterParentheses_optimal(string s) {
    string res = "";
    int balance = 0;
    for (char c : s) {
        if (c == '(') {
            if (balance++) res += c;
        } else {
            if (--balance) res += c;
        }
    }
    return res;
}

