// Problem: Row with minimum number of 1s in a binary matrix
// Link: https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1
// Difficulty: Easy
// Tags: Binary Search, Matrix, Brute Force


class Solution {
  public:
  
    // ✅ Brute Force - O(n * m)
    int minRowBrute(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int minRow = -1;
        int minOnes = m + 1;
        
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) count++;
            }
            if(count < minOnes) {
                minOnes = count;
                minRow = i + 1;
            }
        }
        
        return minRow;
    }
    
    // ✅ Optimal - O(n * log m) using binary search
    int minRowOptimal(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int minRow = -1;
        int minOnes = m + 1;
        
        for(int i = 0; i < n; i++) {
            int low = 0, high = m - 1, firstOneIndex = m;
            while(low <= high) {
                int mid = (low + high) / 2;
                if(mat[i][mid] == 1) {
                    firstOneIndex = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            
            int ones = m - firstOneIndex;
            if(ones < minOnes) {
                minOnes = ones;
                minRow = i + 1;
            }
        }
        
        return minRow;
    }
};

