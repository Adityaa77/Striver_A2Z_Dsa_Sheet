/*
  ✅ Leetcode Problem: 796. Rotate String
  🔗 Link: https://leetcode.com/problems/rotate-string/

  --------------------------
  🧠 Problem Description:
  --------------------------
  Given two strings s and goal, return true if and only if s can become goal after some number of shifts.
  A shift means moving the first character of s to the end.

  --------------------------
  💡 Approaches Used:
  --------------------------

  1️⃣ Brute Force Approach:
     - Rotate the string one character at a time.
     - Check after each rotation whether it matches the target string.
     - Total of n rotations, each involving string slicing/concatenation.
     - Time Complexity: O(n^2)
     - Space Complexity: O(n)

  2️⃣ Optimal Approach:
     - A rotated string must be a substring of s+s.
     - Just check if goal exists in s+s.
     - Time Complexity: O(n)
     - Space Complexity: O(n)

  --------------------------
  ✅ Status: Both solutions tested and accepted on Leetcode
*/

class Solution {
public:

    // 🔸 1. Brute Force Approach
    bool rotateStringBrute(string s, string goal) {
        if (s.length() != goal.length()) return false;

        for (int i = 0; i < s.length(); i++) {
            if (s == goal) return true;

            // Rotate goal by moving the first character to the end
            char firstChar = goal[0];
            goal = goal.substr(1) + firstChar;
        }

        return false;
    }

    // 🔹 2. Optimal Approach
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;

        // If goal is a substring of s+s, then it's a valid rotation
        string concat = s + s;
        return concat.find(goal) != string::npos;
    }
};
