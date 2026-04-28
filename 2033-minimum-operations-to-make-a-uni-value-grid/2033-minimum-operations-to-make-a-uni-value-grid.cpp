class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int m = grid.size(), n = grid[0].size();
        
        // 1. Flatten the grid into a 1D vector
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                nums.push_back(grid[i][j]);
            }
        }
        
        // 2. Check for feasibility: all elements must have same remainder modulo x
        // Use the first element as the reference
        int referenceMod = (nums[0] % x + x) % x; // Handle negative numbers if any
        for (int val : nums) {
            if ((val % x + x) % x != referenceMod) return -1;
        }
        
        // 3. Find the median efficiently using nth_element
        int midIdx = nums.size() / 2;
        nth_element(nums.begin(), nums.begin() + midIdx, nums.end());
        int median = nums[midIdx];
        
        // 4. Calculate total operations required to make all values equal to median
        int totalOps = 0;
        for (int val : nums) {
            totalOps += abs(val - median) / x;
        }
        
        return totalOps;
    }
};
