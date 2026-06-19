class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates,
                   int target,
                   vector<int>& current,
                   int index) {

        if (target == 0) {
            result.push_back(current);
            return;
        }

        if (target < 0)
            return;

        for (int i = index; i < candidates.size(); i++) {

            if (i > index &&
                candidates[i] == candidates[i - 1])
                continue;

            current.push_back(candidates[i]);

            backtrack(candidates,
                      target - candidates[i],
                      current,
                      i + 1); // use once

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(
        vector<int>& candidates,
        int target) {

        sort(candidates.begin(),
             candidates.end());

        vector<int> current;

        backtrack(candidates,
                  target,
                  current,
                  0);

        return result;
    }
};