class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int m = nums1.size();
        int n = nums2.size();
        int result = 0;
        
        while (i < m && j < n) {
            // Check if it's a valid pair: i <= j AND nums1[i] <= nums2[j]
            if (nums1[i] <= nums2[j]) {
                // Since i <= j is required, we only care about distance when i <= j
                // The loop naturally handles this if we only move j when valid
                result = max(result, j - i);
                j++;
            } else {
                // nums1[i] is too large, move to a smaller value in nums1
                i++;
            }
        }
        return result;
    }
};
