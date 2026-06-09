#include <vector>
#include <algorithm>

class Solution {
public:
    long long maxTotalValue(std::vector<int>& nums, int k) {
        // Find both the minimum and maximum elements in a single pass
        auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
        
        // Cast to long long to prevent arithmetic overflow
        return (long long)k * (*max_it - *min_it);
    }
};
