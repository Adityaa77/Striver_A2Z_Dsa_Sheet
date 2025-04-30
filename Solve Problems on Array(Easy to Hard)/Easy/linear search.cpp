
// 🚀 Problem: Linear Search - Find First Occurrence
// 📝 Problem Link: https://takeuforward.org/plus/dsa/problems/linear-search
// ❗ If target is not found, return -1.

// ✅ Time Complexity: O(n), where n is the number of elements in the array
// ✅ Space Complexity: O(1), no extra space used


int linearSearch(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        // If current element is the target, return its index
        if (nums[i] == target) {
            return i;
        }
    }
    // If not found, return -1
    return -1;
}
