class Solution {
public:
    std::vector<std::vector<int>> rotateGrid(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int num_layers = std::min(m, n) / 2;

        for (int layer = 0; layer < num_layers; ++layer) {
            std::vector<int> elements;
            int top = layer, left = layer;
            int bottom = m - 1 - layer, right = n - 1 - layer;

            // 1. Extract elements in counter-clockwise order
            for (int j = left; j < right; ++j) elements.push_back(grid[top][j]);
            for (int i = top; i < bottom; ++i) elements.push_back(grid[i][right]);
            for (int j = right; j > left; --j) elements.push_back(grid[bottom][j]);
            for (int i = bottom; i > top; --i) elements.push_back(grid[i][left]);

            // 2. Calculate effective rotation
            int len = elements.size();
            int net_k = k % len;
            
            // 3. Re-insert elements starting from the net_k-th index
            int idx = net_k;
            for (int j = left; j < right; ++j) { grid[top][j] = elements[idx]; idx = (idx + 1) % len; }
            for (int i = top; i < bottom; ++i) { grid[i][right] = elements[idx]; idx = (idx + 1) % len; }
            for (int j = right; j > left; --j) { grid[bottom][j] = elements[idx]; idx = (idx + 1) % len; }
            for (int i = bottom; i > top; --i) { grid[i][left] = elements[idx]; idx = (idx + 1) % len; }
        }
        return grid;
    }
};
