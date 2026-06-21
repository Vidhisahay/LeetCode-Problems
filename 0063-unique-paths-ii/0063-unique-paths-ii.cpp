//Approach : Tabulation (Bottom Up). 
// T.C : O(m*n)
// S.C : O(m*n)

class Solution {
public:
    int m, n;

    int solve(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        
        // Traverse first column to populate the path possible in DP
        // And to handle stones in the way
        for(int col = 0; col<n; col++) {
            // If previous column cell is a grid then
            // Make the path count in DP for that cell = 0
            // And update the obstacleGrid for that cell = 1 to show there is no path through that cell
            if(col > 0 && obstacleGrid[0][col-1] == 1) {
                dp[0][col] = 0;
                obstacleGrid[0][col] = 1; //Bcz now it's not possible to reach any cell in first row from this cell onwards
            }
            // If the current cell in the obstacleGrid represnts 1 then
            // Mark tha column in DP = 0 since there anre no path possible through/to that cell 
            else if(obstacleGrid[0][col] == 1){
                dp[0][col] = 0;
            }
            // If no obstacles found the there is one path through that cell
            else{
                dp[0][col] = 1;
            }
        }
        
        // Traverse first row to populate the path possible in DP
        // And to handle stones in the way
        for(int row = 0; row<m; row++) {
            // If previous row cell is a grid then
            // Make the path count in DP for that cell = 0
            // And update the obstacleGrid for that cell = 1 to show there is no path through that cell
            if(row > 0 && obstacleGrid[row-1][0] == 1) {
                dp[row][0] = 0;
                obstacleGrid[row][0] = 1; //Bcz now it's not possible to reach any cell in first col from this cell onwards
            }
            // If the current cell in the obstacleGrid represnts 1 then
            // Mark tha row in DP = 0 since there anre no path possible through/to that cell 
            else if(obstacleGrid[row][0] == 1){
                dp[row][0] = 0;
            }
            // If no obstacles found the there is one path through that cell
            else{
                dp[row][0] = 1;
            }
        }
        
        for(int i = 1; i<m; i++) {
            for(int j = 1; j<n; j++) {
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        
        return solve(obstacleGrid);
        
    }
};