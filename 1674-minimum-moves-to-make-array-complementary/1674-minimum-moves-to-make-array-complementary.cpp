class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
      
        // Difference array to track cost changes across different target sums
        // Size is limit*2 + 2 to cover all possible sums from 2 to limit*2
        int costDifference[limit * 2 + 2];
        memset(costDifference, 0, sizeof(costDifference));
      
        // Process each pair (nums[i], nums[n-i-1])
        for (int i = 0; i < n / 2; ++i) {
            int minVal = nums[i];
            int maxVal = nums[n - i - 1];
          
            // Ensure minVal <= maxVal for consistent processing
            if (minVal > maxVal) {
                swap(minVal, maxVal);
            }
          
            // Build difference array based on cost regions:
            // [2, minVal]: cost = 2 (need to change both elements)
            costDifference[2] += 2;
            costDifference[minVal + 1] -= 2;
          
            // [minVal + 1, minVal + maxVal - 1]: cost = 1 (change one element)
            costDifference[minVal + 1] += 1;
            costDifference[minVal + maxVal] -= 1;
          
            // [minVal + maxVal]: cost = 0 (no change needed)
            // No explicit update needed as the difference is 0
          
            // [minVal + maxVal + 1, maxVal + limit]: cost = 1 (change one element)
            costDifference[minVal + maxVal + 1] += 1;
            costDifference[maxVal + limit + 1] -= 1;
          
            // [maxVal + limit + 1, 2 * limit]: cost = 2 (need to change both elements)
            costDifference[maxVal + limit + 1] += 2;
        }
      
        // Find the minimum cost by calculating prefix sum of the difference array
        int minTotalMoves = n;  // Initialize with maximum possible moves
        int currentCost = 0;
      
        for (int targetSum = 2; targetSum <= limit * 2; ++targetSum) {
            currentCost += costDifference[targetSum];
            minTotalMoves = min(minTotalMoves, currentCost);
        }
      
        return minTotalMoves;
    }
};
