#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
🔗 Problem: Longest Consecutive Sequence
Link: https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array/
LeetCode: https://leetcode.com/problems/longest-consecutive-sequence/

Given an unsorted array of integers nums, return the length of the longest sequence of consecutive elements.

Examples:
Input:  nums = [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].

-------------------------------------
Approach 1: Sort + Linear Scan
Time Complexity: O(n log n)
Space Complexity: O(1) (excluding sort)
*/

int longestConsecutiveSorted(vector<int>& nums) {
    if (nums.empty()) return 0;

    sort(nums.begin(), nums.end());
    int cons = 0, con = 0;
    int num = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == num) {
            continue; // ✅ skip duplicates
        }
        if (num == nums[i] - 1) {
            cons++;
        } else {
            con = max(con, cons);
            cons = 0;
        }
        num = nums[i];
    }

    con = max(con, cons);
    return con + 1;
}

/*
-------------------------------------
Approach 2: Using HashSet (Optimal)
Time Complexity: O(n)
Space Complexity: O(n)
*/

int longestConsecutiveSet(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int longest = 0;

    for (int num : s) {
        if (!s.count(num - 1)) {  // Only start counting at the beginning of a sequence
            int current = num;
            int length = 1;

            while (s.count(current + 1)) {
                current++;
                length++;
            }

            longest = max(longest, length);
        }
    }

    return longest;
}
