// ✅ Brute Force Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
// Logic: Linear scan to find the first index where arr[i] >= target

class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int n = arr.size();
        int index = -1; // to store the index when condition is met
        for (int i = 0; i < n; i++) {
            if (arr[i] >= target) {
                index = i;
                return i;  // Return as soon as condition is met
            }
        }
        return n; // If no element >= target is found
    }
};

// ✅ Optimal Approach (Binary Search)
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Logic: Use binary search to find the smallest index where arr[mid] >= target

class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int ans = n; // default answer if no element is >= target

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] >= target) {
                ans = mid;        // possible candidate found
                right = mid - 1;  // search left half for earlier occurrence
            } else {
                left = mid + 1;   // search right half
            }
        }

        return ans;
    }
};
