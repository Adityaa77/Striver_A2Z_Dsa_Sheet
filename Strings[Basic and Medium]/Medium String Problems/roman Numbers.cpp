// 🔗 Problem: https://leetcode.com/problems/roman-to-integer/

// 🧠 Approach:

/*
Roman numerals follow specific rules. To convert a Roman numeral string to an integer:
- Add the value of the current symbol if it's greater than or equal to the next symbol.
- Subtract it if it's smaller (like IV = 5 - 1 = 4).

Example: MCMXCIV
  M  = 1000
  CM = 900  (C before M → subtract 100)
  XC = 90   (X before C → subtract 10)
  IV = 4    (I before V → subtract 1)
Total = 1000 + 900 + 90 + 4 = 1994
*/

// --------------------------------------------------------
// 🚫 Brute-force (Not practical here):
// No meaningful brute-force exists since the structure of Roman numerals is positional and greedy parsing is required.
// Trying all permutations would be inefficient and doesn't apply here.
// --------------------------------------------------------


// ✅ Optimal Solution
class Solution {
public:
    int romanToInt(string s) {
       map<char,int>roman {
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
       };
       int sum=0;
       for(int i=0;i<s.size();i++){
            if (i + 1 < s.size() && roman[s[i]] < roman[s[i + 1]]) {
                sum -= roman[s[i]];
            } else {
                sum += roman[s[i]];
            }
       }
       return sum;
    }
};


// 🕒 Time Complexity: O(n) → we iterate once over the string
// 🧠 Space Complexity: O(1) → fixed map with 7 Roman characters

/*
Example:

Input: "MCMXCIV"
Output: 1994
*/
