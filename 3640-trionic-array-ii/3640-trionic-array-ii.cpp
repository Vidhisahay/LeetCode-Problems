class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        long long ans = LLONG_MIN;

        while (i < n) {
            int l = i;
            i += 1;
            // 1. Strictly increasing part (nums[l...p])
            while (i < n && nums[i - 1] < nums[i]) {
                i += 1;
            }
            if (i == l + 1) { // No increasing part found
                continue;
            }
            int p = i - 1;
            
            // Core sum for the mandatory elements of the trionic structure
            long long s = (long long)nums[p - 1] + nums[p];

            // 2. Strictly decreasing part (nums[p...q])
            while (i < n && nums[i - 1] > nums[i]) {
                s += nums[i];
                i += 1;
            }
            if (i == p + 1 || i == n || nums[i - 1] == nums[i]) {
                // Must have a decreasing part and space for a third increasing part
                continue;
            }
            int q = i - 1;

            // 3. Strictly increasing part (nums[q...r])
            s += nums[i];
            i += 1;
            long long mx_right = 0, current_t = 0;
            while (i < n && nums[i - 1] < nums[i]) {
                current_t += nums[i];
                i += 1;
                mx_right = max(mx_right, current_t);
            }
            s += mx_right;

            // Optional: Maximize the first increasing segment (prefix before p-1)
            long long mx_left = 0, left_t = 0;
            for (int j = p - 2; j >= l; j--) {
                left_t += nums[j];
                mx_left = max(mx_left, left_t);
            }
            s += mx_left;

            ans = max(ans, s);
            
            // Move pointer to q as the next potential start of a trionic subarray
            i = q;
        }
        return ans;
    }
};