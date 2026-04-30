class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int inf = 1e9; // Representation for unreachable paths

        // dp[i][j][c] = max score at (i, j) with exactly c cost
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        // Base case: Starting at (0, 0). grid[0][0] is always 0, so cost is 0.
        dp[0][0][0] = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int c = 0; c <= k; ++c) {
                    if (dp[i][j][c] == -1) continue;

                    // Possible moves: Right and Down
                    int next_coords[2][2] = {{i + 1, j}, {i, j + 1}};
                    for (auto& pos : next_coords) {
                        int ni = pos[0], nj = pos[1];

                        if (ni < m && nj < n) {
                            int next_cost = c + (grid[ni][nj] > 0 ? 1 : 0);
                            int next_score = dp[i][j][c] + grid[ni][nj];

                            if (next_cost <= k) {
                                dp[ni][nj][next_cost] = max(dp[ni][nj][next_cost], next_score);
                            }
                        }
                    }
                }
            }
        }

        // Find the maximum score at the bottom-right corner for any cost <= k
        int max_score = -1;
        for (int c = 0; c <= k; ++c) {
            max_score = max(max_score, dp[m - 1][n - 1][c]);
        }

        return max_score;
    }
};
