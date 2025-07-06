// ✅ Problem: Find Ceil of x in a Sorted Array
// The ceil of x is the smallest element in the array greater than or equal to x.
// If no such element exists, return -1.

// ---------------------------------------------------------
// ✅ Approach 1: Brute Force
// Time Complexity: O(n)
// Space Complexity: O(1)
// Traverse through the array to find the smallest element >= x
// ---------------------------------------------------------

class BruteSolution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] >= x) {
                return i;  // First element >= x
            }
        }
        return -1; // No element >= x found
    }
};

// ---------------------------------------------------------
// ✅ Approach 2: Optimal Approach using Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Use binary search to find the lowest index with value >= x
// ---------------------------------------------------------

class OptimalSolution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int ans = -1;  // Default to -1 if no ceil exists

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] >= x) {
                ans = mid;       // Possible ceil found
                right = mid - 1; // Try to find a smaller index
            } else {
                left = mid + 1;  // Need to search larger values
            }
        }
        return ans;
    }
};
