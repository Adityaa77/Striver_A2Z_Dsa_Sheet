// 🔹 LeetCode 73: Set Matrix Zeroes
// 🔗 Problem Link: https://leetcode.com/problems/set-matrix-zeroes/

// ✅ Approach 1: Better (Using Extra Space)
// 🕒 Time: O(m * n),  🧠 Space: O(m + n)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<int> rows(r, 0); // Row marker
        vector<int> cols(c, 0); // Column marker

        // 🔸 First pass: mark rows and columns that need to be zeroed
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }

        // 🔸 Second pass: set values to 0 based on markers
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// ✅ Approach 2: Optimal (Constant Space)
// 🕒 Time: O(m * n),  🧠 Space: O(1)
// ⚠️ Modifies matrix in-place using first row and column as markers

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        bool col0 = false;

        // 🔸 Step 1: use first row and column to mark 0s
        for (int i = 0; i < r; i++) {
            if (matrix[i][0] == 0) col0 = true; // separate flag for first col
            for (int j = 1; j < c; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // mark row
                    matrix[0][j] = 0; // mark column
                }
            }
        }

        // 🔸 Step 2: apply the marks in reverse to avoid overwriting markers
        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (col0) matrix[i][0] = 0; // handle first column
        }
    }
};
