// ✅ Problem: Find Floor of x in a Sorted Array
// Floor of x is the largest element in the array which is smaller than or equal to x.
// If no such element exists, return -1.

// -------------------------------------------------------------------------
// ✅ Approach 1: Brute Force
// Time Complexity: O(n)
// Space Complexity: O(1)
// Loop through the array to find the max element less than or equal to x
// -------------------------------------------------------------------------

class BruteSolution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int floor = -1;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] <= x) {
                floor = i; // store index of last smaller/equal value
            } else {
                break; // since array is sorted, no need to continue
            }
        }
        return floor;
    }
};

// -------------------------------------------------------------------------
// ✅ Approach 2: Optimal using Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Classic lower bound technique for floor using binary search
// -------------------------------------------------------------------------

class OptimalSolution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int ans = -1;  // Default if floor doesn't exist

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] <= x) {
                ans = mid;       // Possible floor found
                left = mid + 1;  // Move right to find larger value ≤ x
            } else {
                right = mid - 1; // Move left to find smaller value
            }
        }
        return ans;
    }
};
