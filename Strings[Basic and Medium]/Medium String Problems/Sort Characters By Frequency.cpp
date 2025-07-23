// LeetCode Problem: 451. Sort Characters By Frequency
// Link: https://leetcode.com/problems/sort-characters-by-frequency/
// Language: C++
// Author: Aditya
// Approach: Use a hash map to count character frequencies and a max-heap to sort by frequency.

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp; // To store frequency of each character
        
        // Count frequency of each character in the string
        for (char ch : s) {
            mpp[ch]++;
        }

        // Max-heap to sort characters by frequency
        priority_queue<pair<int, char>> pq;
        for (auto it : mpp) {
            pq.push({it.second, it.first}); // {frequency, character}
        }

        string ans = ""; // Final answer string
        
        // Build the output string based on highest frequency first
        while (!pq.empty()) {
            auto curr = pq.top(); // Get character with highest frequency
            pq.pop();
            ans += string(curr.first, curr.second); // Append character 'freq' times
        }

        return ans;
    }
};
