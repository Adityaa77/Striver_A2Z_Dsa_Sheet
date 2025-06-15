// ✅ Leetcode 54: Spiral Matrix
// 🔗 https://leetcode.com/problems/spiral-matrix/

// ✅ Approach:
// We use 4 pointers: top, bottom, left, right to simulate the spiral traversal.
// 1. Move Left to Right on top row → then increment top.
// 2. Move Top to Bottom on right column ↓ then decrement right.
// 3. Move Right to Left on bottom row ← then decrement bottom (only if top ≤ bottom).
// 4. Move Bottom to Top on left column ↑ then increment left (only if left ≤ right).
// Repeat this while top <= bottom and left <= right.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();         // number of rows
        int m = matrix[0].size();      // number of columns
        vector<int> arr;

        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;

        while (top <= bottom && left <= right) {
            // Step 1: Move → on top row
            for (int i = left; i <= right; i++) {
                arr.push_back(matrix[top][i]);
            }
            top++;

            // Step 2: Move ↓ on right column
            for (int i = top; i <= bottom; i++) {
                arr.push_back(matrix[i][right]);
            }
            right--;

            // Step 3: Move ← on bottom row (only if top <= bottom)
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    arr.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Step 4: Move ↑ on left column (only if left <= right)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    arr.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return arr;
    }
};
