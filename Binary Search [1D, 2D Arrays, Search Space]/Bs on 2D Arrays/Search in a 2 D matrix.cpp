// Problem: 74. Search a 2D Matrix
// Link: https://leetcode.com/problems/search-a-2d-matrix/
// Given an m x n matrix where each row is sorted in ascending order,
// and the first integer of each row is greater than the last integer of the previous row,
// return true if target is in the matrix and false otherwise.

// ✅ Brute Force Approach
// 🔍 Time Complexity: O(n * m)
// 🔧 Space Complexity: O(1)
// 📌 Check every element in the matrix
class BruteForceSolution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }
};


// ✅ Optimal Approach (Row-wise Binary Search)
// 🔍 Time Complexity: O(n * log m)
// 🔧 Space Complexity: O(1)
// 📌 For each row, use binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            int low = 0, high = m - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (matrix[i][mid] == target) {
                    return true;
                } else if (matrix[i][mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};

/*
🧠 Summary:
- Brute Force: Traverse the entire matrix.
- Optimal: Binary search each row to reduce time.
- Further Optimal: Treat entire matrix as 1D and binary search in O(log(n*m)).
*/
