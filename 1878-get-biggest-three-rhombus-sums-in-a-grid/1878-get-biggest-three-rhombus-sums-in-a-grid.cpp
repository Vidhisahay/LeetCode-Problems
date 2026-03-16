class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> unique_sums;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Radius 0: just the cell itself
                unique_sums.insert(grid[i][j]);

                // Expand radius k
                for (int k = 1; ; ++k) {
                    int top = i - k, bottom = i + k;
                    int left = j - k, right = j + k;

                    // Stop if the rhombus hits any boundary
                    if (top < 0 || bottom >= m || left < 0 || right >= n) break;

                    long long current_sum = 0;
                    // Add the 4 corners once
                    current_sum += grid[top][j];
                    current_sum += grid[bottom][j];
                    current_sum += grid[i][left];
                    current_sum += grid[i][right];

                    // Add the elements on the 4 edges (excluding corners)
                    for (int d = 1; d < k; ++d) {
                        current_sum += grid[top + d][j + d]; // top to right
                        current_sum += grid[top + d][j - d]; // top to left
                        current_sum += grid[bottom - d][j + d]; // bottom to right
                        current_sum += grid[bottom - d][j - d]; // bottom to left
                    }
                    
                    unique_sums.insert(current_sum);
                }
            }
        }

        // Convert set to descending vector
        vector<int> res(unique_sums.rbegin(), unique_sums.rend());
        if (res.size() > 3) res.resize(3);
        return res;
    }
};
