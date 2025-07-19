// Problem: 240. Search a 2D Matrix II
// Link: https://leetcode.com/problems/search-a-2d-matrix-ii/
// Tags: Matrix, Binary Search, Brute Force, Optimized
// Difficulty: Medium
// Status: Solved ✅

class Solution {
public:
    // Brute Force Approach — Time: O(n * m), Space: O(1)
    bool searchMatrixBrute(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }

    // Optimized Approach (Staircase Search) — Time: O(n + m), Space: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;

        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                row++;
            }
            else {
                col--;
            }
        }
        return false;
    }
};
