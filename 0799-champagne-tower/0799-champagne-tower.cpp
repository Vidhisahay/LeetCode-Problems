class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // Create a 2D array to simulate the champagne tower
        // dp[i][j] represents the amount of champagne in glass at row i, position j
        double dp[101][101] = {0.0};
      
        // Pour all champagne into the top glass
        dp[0][0] = poured;
      
        // Process each row from top to query_row
        for (int row = 0; row <= query_row; ++row) {
            // Process each glass in the current row
            for (int glass = 0; glass <= row; ++glass) {
                // If current glass has more than 1 cup of champagne
                if (dp[row][glass] > 1) {
                    // Calculate the overflow amount that spills to glasses below
                    double overflow = (dp[row][glass] - 1) / 2.0;
                  
                    // Current glass can only hold 1 cup
                    dp[row][glass] = 1;
                  
                    // Distribute overflow equally to the two glasses below
                    dp[row + 1][glass] += overflow;         // Left child glass
                    dp[row + 1][glass + 1] += overflow;     // Right child glass
                }
            }
        }
      
        // Return the amount of champagne in the queried glass
        return dp[query_row][query_glass];
    }
};