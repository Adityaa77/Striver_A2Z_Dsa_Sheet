// 🔗 GFG Problem Link: https://www.geeksforgeeks.org/problems/rotation4723/1

// ✅ Problem Statement:
// Given a sorted and rotated array 'arr' of size 'n', find the number of times the array has been rotated.
// This is equivalent to finding the index of the minimum element in the array.

// ----------------------------------------------------------------------------------
// ✅ Brute Force Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
// Logic: Traverse the array and find the index of the minimum element.

class BruteSolution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int minVal = INT_MAX;
        int index = -1;

        for (int i = 0; i < n; i++) {
            if (arr[i] < minVal) {
                minVal = arr[i];
                index = i;
            }
        }

        return index; // This index is the rotation count.
    }
};

// ----------------------------------------------------------------------------------
// ✅ Optimal Binary Search Approach
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Logic: Use binary search to find the index of the minimum element (rotation point).

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int ans = INT_MAX;
        int index = 0;

        while (left <= right) {
            int mid = (left + right) / 2;

            // Case 1: Whole subarray is sorted
            if (arr[left] <= arr[right]) {
                if (arr[left] < ans) {
                    ans = arr[left];
                    index = left;
                }
                break;
            }

            // Case 2: Left half is sorted
            if (arr[left] <= arr[mid]) {
                if (arr[left] < ans) {
                    ans = arr[left];
                    index = left;
                }
                left = mid + 1;
            }

            // Case 3: Right half is sorted
            else {
                if (arr[mid] < ans) {
                    ans = arr[mid];
                    index = mid;
                }
                right = mid - 1;
            }
        }

        return index; // index of the minimum element = number of rotations
    }
};
