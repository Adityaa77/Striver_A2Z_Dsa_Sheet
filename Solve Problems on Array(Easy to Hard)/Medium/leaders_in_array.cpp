#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// ✅ Problem: Leaders in an Array--https://takeuforward.org/plus/dsa/problems/leaders-in-an-array
// A leader is an element strictly greater than all elements to its right.
// Rightmost element is always a leader.
// Maintain the original order in the output.

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        int maxi = INT_MIN;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > maxi) {
                result.push_back(nums[i]);  // it's a leader
                maxi = nums[i];
            }
        }

        // Reverse to restore original order
        reverse(result.begin(), result.end());
        return result;
    }
};
