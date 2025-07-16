// Leetcode 1539: Kth Missing Positive Number
// Problem: https://leetcode.com/problems/kth-missing-positive-number/

class Solution {
public:

    // ✅ BRUTE FORCE APPROACH
    // Time: O(k + n) | Space: O(k)
    // We count missing numbers starting from 1 and skip the ones in arr.
    int findKthPositiveBrute(vector<int>& arr, int k) {
        vector<int> missing;     // stores missing numbers
        int i = 0, num = 1;
        int n = arr.size();

        while (missing.size() < k) {
            if (i < n && arr[i] == num) {
                i++; // number exists in array, not missing
            } else {
                missing.push_back(num); // number is missing
            }
            num++;
        }

        return missing[k - 1];
    }

    // ⚡ OPTIMIZED BINARY SEARCH APPROACH
    // Time: O(log n) | Space: O(1)
    // Key: arr[i] - (i + 1) gives count of missing numbers before index i
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // missing count till index mid
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // At the end, left = number of non-missing elements before result
        // So k-th missing is at position: left + k
        return left + k;
    }
};
