class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target,
                   vector<int>& current, int index) {

        if (target == 0) {
            result.push_back(current);
            return;
        }

        if (target < 0)
            return;

        for (int i = index; i < candidates.size(); i++) {

            current.push_back(candidates[i]);

            backtrack(candidates,
                      target - candidates[i],
                      current,
                      i);   // reuse allowed

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        vector<int> current;

        backtrack(candidates, target, current, 0);

        return result;
    }
};