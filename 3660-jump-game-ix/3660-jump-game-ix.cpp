class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> preMax(n);

        // Step 1: Build prefix maximum array
        preMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            preMax[i] = max(preMax[i - 1], nums[i]);
        }

        // Step 2: Backward pass using suffix minimum
        int sufMin = 1e9 + 7; // Use a value larger than any possible nums[i]
        for (int i = n - 1; i >= 0; --i) {
            // Rule: If current prefix max can 'bridge' via a smaller value to the right
            if (i < n - 1 && preMax[i] > sufMin) {
                ans[i] = ans[i + 1];
            } else {
                ans[i] = preMax[i];
            }
            // Update suffix minimum for the next element to the left
            sufMin = min(sufMin, nums[i]);
        }

        return ans;
    }
};
