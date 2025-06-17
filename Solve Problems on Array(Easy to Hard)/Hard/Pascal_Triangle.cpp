/*
🔁 STATUS: TO REVISE
This question (Leetcode 118. Pascal's Triangle) was not fully understood on the first try.
The current solution is working, but the logic behind how each row is built and how the indices
relate to the previous row should be revised again later for full clarity.

🧠 Key Concept:
In Pascal's Triangle, each row starts and ends with 1.
Each inner element is the sum of the two numbers directly above it from the previous row.

Example:
Row 0:        [1]
Row 1:       [1, 1]
Row 2:      [1, 2, 1]    --> 2 = 1 + 1
Row 3:     [1, 3, 3, 1]  --> 3 = 1+2, 3 = 2+1

---

🧩 Approach:
1. Start from row 0 to numRows-1.
2. For each row, create a vector of size (i+1), initialized with 1s.
3. Fill in the middle values from the previous row using:
   row[j] = triangle[i-1][j-1] + triangle[i-1][j]
4. Push the constructed row to the main result.

🛠️ Time Complexity: O(numRows^2)
🛠️ Space Complexity: O(numRows^2) for the triangle

📌 Leetcode: https://leetcode.com/problems/pascals-triangle/
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);  // All rows start and end with 1

            // Fill inner values of the row (not first or last)
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};

