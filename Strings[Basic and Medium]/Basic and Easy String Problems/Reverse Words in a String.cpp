// 🔗 Leetcode Problem: 151. Reverse Words in a String
// 🧠 Approach: Reverse entire string, then reverse each word individually, skip extra spaces
// ⏱️ Time Complexity: O(N)
// 🗃️ Space Complexity: O(1) (excluding answer string)
// ✅ Status: Optimal for interviews and real-world use cases

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string answer = "";

        // Step 1: Reverse entire string
        reverse(s.begin(), s.end());

        // Step 2: Traverse and reverse each word
        for (int i = 0; i < n; i++) {
            string word = "";

            // Skip spaces
            while (i < n && s[i] == ' ') i++;

            // Build the word
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Reverse the word to correct order
            reverse(word.begin(), word.end());

            if (!word.empty()) {
                answer += " " + word;
            }
        }

        // Step 3: Remove leading space
        return answer.substr(1);
    }
};
