class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> result(n);
      
        // Group indices by their values
        unordered_map<int, vector<int>> valueToIndices;
        for (int i = 0; i < n; ++i) {
            valueToIndices[nums[i]].push_back(i);
        }
      
        // Process each group of same values
        for (auto& [value, indices] : valueToIndices) {
            int groupSize = indices.size();
          
            // Initialize left and right sums for the first element in the group
            // leftSum: sum of distances to all elements on the left
            long long leftSum = 0;
            // rightSum: sum of distances to all elements on the right
            // Initially, all elements are on the right of index 0
            long long rightSum = -1LL * groupSize * indices[0];
            for (int index : indices) {
                rightSum += index;
            }
          
            // Calculate distance sum for each element in the group
            for (int i = 0; i < groupSize; ++i) {
                // Total distance is sum of left distances and right distances
                result[indices[i]] = leftSum + rightSum;
              
                // Update left and right sums for the next element
                if (i + 1 < groupSize) {
                    int gap = indices[i + 1] - indices[i];
                    // Elements on the left (including current) will increase distance by gap
                    leftSum += gap * (i + 1);
                    // Elements on the right will decrease distance by gap
                    rightSum -= gap * (groupSize - i - 1);
                }
            }
        }
      
        return result;
    }
};
