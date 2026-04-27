class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Directions: {row_offset, col_offset}
        // Indices: 0: Up, 1: Right, 2: Down, 3: Left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        // street_dirs[street_type] = {first_dir, second_dir}
        // Using 1-based indexing to match street types
        int street_dirs[7][2] = {
            {0, 0},    // dummy
            {1, 3},    // Type 1: Right, Left
            {0, 2},    // Type 2: Up, Down
            {2, 3},    // Type 3: Down, Left
            {1, 2},    // Type 4: Right, Down
            {0, 3},    // Type 5: Up, Left
            {0, 1}     // Type 6: Up, Right
        };

        queue<pair<int, int>> q;
        q.push({0, 0});
        
        // Use the grid itself or a bitset to save space if needed. 
        // Here we use a 2D vector for clarity, but grid[r][c] = 0 could mark visited.
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1) return true;

            int type = grid[r][c];
            for (int i = 0; i < 2; ++i) {
                int dir = street_dirs[type][i];
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                // 1. Boundary Check
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    int nType = grid[nr][nc];
                    int backDir = (dir + 2) % 4; // The direction to look "back"

                    // 2. Connection Check: Does the neighbor connect back to the current cell?
                    if (street_dirs[nType][0] == backDir || street_dirs[nType][1] == backDir) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return false;
    }
};
