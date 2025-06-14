// LeetCode Problem: 48. Rotate Image
// Link: https://leetcode.com/problems/rotate-image/
// Difficulty: Medium
// Tags: Array, Matrix

// ✅ Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
// Logic: Use an extra matrix to store the rotated result
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> mainmatrix(n, vector<int>(n, 0)); // Create a temp matrix

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mainmatrix[j][n - 1 - i] = matrix[i][j]; // Rotate elements
            }
        }

        matrix = mainmatrix; // Copy result back to original matrix
    }
};

// ✅ Optimal In-Place Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Logic: Transpose the matrix and then reverse each row
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix (swap across the diagonal)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row to complete 90-degree rotation
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
