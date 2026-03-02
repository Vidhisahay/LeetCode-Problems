class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
      
        // Store the rightmost position of 1 in each row
        // If a row has all 0s, the position will be -1
        vector<int> rightmostOnePosition(n, -1);
      
        // Find the rightmost 1 in each row
        for (int row = 0; row < n; ++row) {
            for (int col = n - 1; col >= 0; --col) {
                if (grid[row][col] == 1) {
                    rightmostOnePosition[row] = col;
                    break;
                }
            }
        }
      
        int totalSwaps = 0;
      
        // For each row position, find a suitable row that can be placed here
        for (int targetRow = 0; targetRow < n; ++targetRow) {
            int foundRow = -1;
          
            // Search for the first row that can be placed at targetRow position
            // A row can be placed at position i if its rightmost 1 is at position <= i
            for (int candidateRow = targetRow; candidateRow < n; ++candidateRow) {
                if (rightmostOnePosition[candidateRow] <= targetRow) {
                    totalSwaps += candidateRow - targetRow;
                    foundRow = candidateRow;
                    break;
                }
            }
          
            // If no suitable row is found, it's impossible to form valid matrix
            if (foundRow == -1) {
                return -1;
            }
          
            // Bubble the found row up to its target position
            // by swapping it with previous rows
            for (int currentPos = foundRow; currentPos > targetRow; --currentPos) {
                swap(rightmostOnePosition[currentPos], rightmostOnePosition[currentPos - 1]);
            }
        }
      
        return totalSwaps;
    }
};