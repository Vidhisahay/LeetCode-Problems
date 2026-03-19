class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // 2D prefix sums to store counts of 'X' and 'Y'
        // Using rows+1 and cols+1 to handle boundary conditions easily
        vector<vector<int>> countX(rows + 1, vector<int>(cols + 1, 0));
        vector<vector<int>> countY(rows + 1, vector<int>(cols + 1, 0));
        
        int result = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Determine if current cell contributes to X or Y
                int isX = (grid[i][j] == 'X') ? 1 : 0;
                int isY = (grid[i][j] == 'Y') ? 1 : 0;

                // Standard 2D Prefix Sum formula: 
                // Current = Self + Top + Left - TopLeft
                countX[i + 1][j + 1] = isX + countX[i][j + 1] + countX[i + 1][j] - countX[i][j];
                countY[i + 1][j + 1] = isY + countY[i][j + 1] + countY[i + 1][j] - countY[i][j];

                // Condition: X and Y counts are equal AND there's at least one X
                if (countX[i + 1][j + 1] == countY[i + 1][j + 1] && countX[i + 1][j + 1] > 0) {
                    result++;
                }
            }
        }

        return result;
    }
};
