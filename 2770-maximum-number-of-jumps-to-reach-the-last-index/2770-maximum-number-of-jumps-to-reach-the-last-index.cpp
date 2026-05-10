class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
      
        // dp[i] stores the maximum number of jumps from index i to the last index
        // -1 means not yet computed, negative values mean impossible to reach end
        vector<int> dp(n, -1);
      
        // DFS with memoization to find maximum jumps from current index
        function<int(int)> dfs = [&](int currentIndex) -> int {
            // Base case: reached the last index
            if (currentIndex == n - 1) {
                return 0;
            }
          
            // Return memoized result if already computed
            if (dp[currentIndex] != -1) {
                return dp[currentIndex];
            }
          
            // Initialize with a large negative value (indicating impossible path)
            dp[currentIndex] = INT_MIN / 2;
          
            // Try jumping to all valid positions from current index
            for (int nextIndex = currentIndex + 1; nextIndex < n; ++nextIndex) {
                // Check if jump is valid (absolute difference <= target)
                if (abs(nums[currentIndex] - nums[nextIndex]) <= target) {
                    // Update maximum jumps by taking this path
                    dp[currentIndex] = max(dp[currentIndex], 1 + dfs(nextIndex));
                }
            }
          
            return dp[currentIndex];
        };
      
        // Start DFS from index 0
        int result = dfs(0);
      
        // Return -1 if no valid path exists, otherwise return the result
        return result < 0 ? -1 : result;
    }
};