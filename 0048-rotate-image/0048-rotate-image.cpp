class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
      
        // Step 1: Flip the matrix horizontally (reverse rows)
        // Swap the first row with the last row, second with second-to-last, etc.
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
      
        // Step 2: Transpose the matrix (swap along the diagonal)
        // Swap element at position (i, j) with element at position (j, i)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};