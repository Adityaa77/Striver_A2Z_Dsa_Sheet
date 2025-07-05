// ✅ Brute Force Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
// ✅ Idea: Simply loop through the array and return the first index where arr[i] > target

class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int n = arr.size();
        int index = -1;  // stores result if found

        for (int i = 0; i < n; i++) {
            if (arr[i] > target) {
                index = i;
                return i;  // found the first element > target
            }
        }

        return n; // all elements are <= target
    }
};

// ✅ Optimal Approach (Binary Search)
// Time Complexity: O(log n)
// Space Complexity: O(1)
// ✅ Idea: Use binary search to find the first element > target in sorted array

class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int ans = n;  // default if no element > target

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] > target) {
                ans = mid;        // possible answer
                right = mid - 1;  // look for smaller index
            } else {
                left = mid + 1;   // move right
            }
        }

        return ans;
    }
};
