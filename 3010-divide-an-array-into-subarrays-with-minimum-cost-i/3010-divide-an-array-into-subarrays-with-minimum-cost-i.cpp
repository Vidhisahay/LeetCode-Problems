class Solution {
public:
    int minimumCost(vector<int>& nums) {
        // First element is always included in the sum
        int firstElement = nums[0];
      
        // Initialize the two smallest values from the remaining elements
        // Using 100 as initial value (assuming it's larger than any element in nums)
        int smallest = 100;
        int secondSmallest = 100;
      
        // Find the two smallest elements from index 1 onwards
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < smallest) {
                // Current element becomes the new smallest
                // Previous smallest becomes second smallest
                secondSmallest = smallest;
                smallest = nums[i];
            } else if (nums[i] < secondSmallest) {
                // Current element is only smaller than second smallest
                secondSmallest = nums[i];
            }
        }
      
        // Return the sum of first element and two smallest elements from the rest
        return firstElement + smallest + secondSmallest;
    }
};