// Problem: 1752. Check if Array Is Sorted and Rotated
// Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0; // To count the number of 'decreasing' points

        // Step 1: Traverse and count how many times nums[i] > nums[i+1]
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i+1]) {
                count++; // Found one drop (decreasing point)
            }
        }

        // Step 2: Also check circularly from last element to first element
        // Because rotation can make last element > first element
        if (nums[n-1] > nums[0]) {
            count++;
        }

        // Step 3: If there is 0 or 1 drop, it is sorted and rotated properly
        // Else, it is not sorted and rotated
        if (count <= 1) {
            return true; // Valid sorted and rotated array
        }
        else {
            return false; // Invalid array
        }
    }
};

/*

⏳ Time Complexity: 
- O(N), where N = size of array
- We only do a single pass over the array.

🛢️ Space Complexity:
- O(1)
- Only extra integer variable `count` is used.

*/
