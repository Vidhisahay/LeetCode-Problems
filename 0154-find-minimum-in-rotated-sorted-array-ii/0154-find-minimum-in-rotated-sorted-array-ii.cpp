class Solution {
public:
    int findMin(vector<int>& nums) {
        // Initialize binary search boundaries
        int left = 0;
        int right = nums.size() - 1;
      
        // Binary search to find the minimum element
        while (left < right) {
            // Calculate middle index using bit shift (equivalent to dividing by 2)
            int mid = (left + right) >> 1;
          
            // If mid element is greater than right element,
            // the minimum must be in the right half (after mid)
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // If mid element is less than right element,
            // the minimum is in the left half (including mid)
            else if (nums[mid] < nums[right]) {
                right = mid;
            }
            // If mid element equals right element (duplicates case),
            // we can't determine which side has the minimum,
            // so we safely reduce the search space by moving right pointer left
            else {
                --right;
            }
        }
      
        // When left == right, we've found the minimum element
        return nums[left];
    }
};