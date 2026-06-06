class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
      
        // Result vector to store the absolute differences
        vector<int> result;
      
        // Iterate through each element in the array
        for (int& num : nums) {
            // Exclude current element from right sum
            rightSum -= num;
          
            // Calculate absolute difference between left and right sums
            result.push_back(abs(leftSum - rightSum));
          
            // Include current element in left sum for next iteration
            leftSum += num;
        }
      
        return result;
    }
};