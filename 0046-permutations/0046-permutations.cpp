class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int index) {

        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {

            swap(nums[index], nums[i]);

            backtrack(nums, index + 1);

            swap(nums[index], nums[i]); // backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        backtrack(nums, 0);

        return result;
    }
};