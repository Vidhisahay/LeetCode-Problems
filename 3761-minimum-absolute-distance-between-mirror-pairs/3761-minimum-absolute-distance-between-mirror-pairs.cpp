class Solution {
public:
    int minMirrorPairDistance(std::vector<int>& nums) {
        int n = nums.size();
        // Use a hash map to store the most recent index of a reversed number
        std::unordered_map<int, int> last_seen;
        int min_dist = INT_MAX;

        for (int j = 0; j < n; ++j) {
            // 1. Check if the current number nums[j] is the reverse of a previous number
            if (last_seen.count(nums[j])) {
                min_dist = std::min(min_dist, j - last_seen[nums[j]]);
            }

            // 2. Reverse the current number and store its latest index
            int rev = reverseNum(nums[j]);
            last_seen[rev] = j;
        }

        return (min_dist == INT_MAX) ? -1 : min_dist;
    }

private:
    // Helper to reverse an integer as per the problem rules (omit leading zeros)
    int reverseNum(int n) {
        long long res = 0; // Use long long to prevent overflow during reversal
        while (n > 0) {
            res = res * 10 + (n % 10);
            n /= 10;
        }
        return (int)res;
    }
};
