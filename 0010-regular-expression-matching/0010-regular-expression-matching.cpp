class Solution {
public:
    int helper(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        // Base Cases
        if (i == j && j == -1) return 1;
        if (j == -1 && i != -1) return 0;
        if (i == -1) {
            if (p[j] == '*') return helper(s, p, i, j - 2, dp);
            else return 0;
        }
        
        // Return cached result if already evaluated
        if (dp[i][j] != -1) return dp[i][j];
        
        // Case 1: Exact match or '.' wildcard
        if (s[i] == p[j] || p[j] == '.') {
            return dp[i][j] = helper(s, p, i - 1, j - 1, dp);
        }
        
        // Case 2: Mismatch without '*'
        if (s[i] != p[j] && p[j] != '*') {
            return dp[i][j] = 0;
        }
        
        // Case 3: '*' wildcard where preceding character doesn't match s[i]
        if (s[i] != p[j - 1] && p[j - 1] != '.') {
            return dp[i][j] = helper(s, p, i, j - 2, dp);
        }
        
        // Case 4: '*' wildcard where preceding character matches s[i] (0 or multiple matches)
        return dp[i][j] = (helper(s, p, i, j - 2, dp) || helper(s, p, i - 1, j, dp));
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));
        return helper(s, p, s.length() - 1, p.length() - 1, dp) == 1;
    }
};