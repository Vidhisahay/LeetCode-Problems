class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        if(ob[0][0]==1 || ob.empty())return 0;
        int n=ob.size();
        int m=ob[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ob[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }

                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }

                int up=0;
                int left=0;

                if(i > 0){
                    up=dp[i-1][j];
                }

                if(j > 0){
                    left=dp[i][j-1];
                }

                dp[i][j]=left+up;
            }
        }

        return dp[n-1][m-1];
    }
};