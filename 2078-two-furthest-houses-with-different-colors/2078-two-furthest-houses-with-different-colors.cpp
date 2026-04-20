class Solution {
public:
    int maxDistance(vector<int>& colors) {
        // Initialize maximum distance and get array size
        int maxDist = 0;
        int n = colors.size();
      
        // Check all pairs of indices where i < j
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // If colors at indices i and j are different
                if (colors[i] != colors[j]) {
                    // Update maximum distance (j - i is always positive since j > i)
                    maxDist = max(maxDist, j - i);
                }
            }
        }
      
        return maxDist;
    }
};