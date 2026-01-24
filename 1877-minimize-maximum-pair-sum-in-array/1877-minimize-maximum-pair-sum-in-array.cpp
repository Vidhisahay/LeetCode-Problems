class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // Sort the array in ascending order
        sort(nums.begin(), nums.end());
      
        // Initialize the maximum pair sum
        int max_pair_sum = 0;
        int n = nums.size();
      
        // Pair the smallest with the largest, second smallest with second largest, etc.
        // This greedy approach minimizes the maximum pair sum
        for (int i = 0; i < n / 2; ++i) {
            // Calculate the sum of current pair (i-th smallest and i-th largest)
            int current_pair_sum = nums[i] + nums[n - i - 1];
          
            // Update the maximum pair sum if current pair sum is larger
            max_pair_sum = max(max_pair_sum, current_pair_sum);
        }
      
        return max_pair_sum;
    }
};