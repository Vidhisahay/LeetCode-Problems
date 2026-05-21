class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // edge cases
        if (n == 1) return nums[0]; //single element
        if (nums[0] != nums[1]) return nums[0]; //first element is unique
        if (nums[n-1] != nums[n-2]) return nums[n-1]; // last element is unique

        // bich ka elements k liye binary search
        int low = 1, high = n-2;
        while(low <= high){
            int mid = low + (high - low)/2;

            //if mid is unique
            if (nums[mid] != nums[mid +1] && nums[mid] != nums[mid-1]){
                return nums[mid];
            }

            // If mid is in the left half
            if ((mid % 2 == 1 && nums[mid] == nums[mid-1]) || (mid % 2 == 0 && nums[mid] == nums[mid+1])){
                low = mid + 1;
            }

            else{
                high = mid -1;
            }

        }

        return -1;
    }
};