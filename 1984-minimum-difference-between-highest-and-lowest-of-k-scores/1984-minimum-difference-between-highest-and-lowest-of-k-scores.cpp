class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // Sort the array in ascending order to group similar values together
        sort(nums.begin(), nums.end());
      
        // Initialize the minimum difference with a large value (maximum possible)
        int minDiff = 100000;
      
        // Iterate through all possible windows of size k
        // We need to check windows starting from index 0 to index (n - k)
        for (int i = 0; i <= nums.size() - k; ++i) {
            // Calculate the difference between the last and first element in the current window
            // Window spans from index i to index (i + k - 1)
            int currentDiff = nums[i + k - 1] - nums[i];
          
            // Update the minimum difference if current window has a smaller difference
            minDiff = min(minDiff, currentDiff);
        }
      
        // Return the minimum difference found among all windows
        return minDiff;
    }
};