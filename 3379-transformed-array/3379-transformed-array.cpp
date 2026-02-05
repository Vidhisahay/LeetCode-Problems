class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
      
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                // If current element is 0, result at index i is 0
                result[i] = 0;
            } else {
                // Calculate the target index with circular array handling
                // (i + nums[i] % n + n) % n ensures proper wrapping for both positive and negative values
                // - nums[i] % n: reduces the offset to within array bounds
                // - + n: handles negative values to ensure positive result
                // - final % n: wraps around if index exceeds array size
                int targetIndex = (i + nums[i] % n + n) % n;
                result[i] = nums[targetIndex];
            }
        }
      
        return result;
    }
};
