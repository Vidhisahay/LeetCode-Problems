class Solution {
public:
    pair<int,int> dfs(vector<string>& b,int i,int j,vector<vector<pair<int,int>>> & dp)
    {
        if(i<0 || j<0 || b[i][j]=='X')
        return {0,0};
        if(i==0 && j==0)
        return {0,1};
        if(dp[i][j].first!=-1 && dp[i][j].second!=-1)
        return dp[i][j];
        auto x=dfs(b,i-1,j,dp);
        auto y=dfs(b,i,j-1,dp);
        auto z=dfs(b,i-1,j-1,dp);
        int maxi=max(x.first,max(y.first,z.first));
        int count=0;
        if(x.first==maxi)
        count=(count+x.second)%(1000000000+7);
        if(y.first==maxi)
        count=(count+y.second)%(1000000000+7);
        if(z.first==maxi)
        count=(count+z.second)%(1000000000+7);
        if(maxi==0 && count==0)
        return dp[i][j]={0,0};
        else if(i==b.size()-1 && j==b[0].size()-1)
        return dp[i][j]={maxi,count};
        return dp[i][j]={maxi+b[i][j]-'0',count};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        vector<vector<pair<int,int>>> dp(board.size(),vector<pair<int,int>>(board[0].size(),{-1,-1}));   
        auto x=dfs(board,board.size()-1,board[0].size()-1,dp);
        return {x.first,x.second};
    }
};