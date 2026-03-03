class Solution {
public:
    char findKthBit(int n, int k) {
        // Lambda function to recursively find the bit value at position k in string Sn
        function<int(int, int)> dfs = [&](int n, int k) {
            // Base case: The first bit is always 0
            if (k == 1) {
                return 0;
            }
          
            // Check if k is a power of 2 (middle position)
            // When k is a power of 2, it represents the middle '1' in the pattern
            if ((k & (k - 1)) == 0) {
                return 1;
            }
          
            // Calculate the total length of string Sn
            // Length of Sn = 2^n - 1
            int totalLength = 1 << n;
          
            // If k is in the first half (before middle)
            // The first half is identical to Sn-1
            if (k * 2 < totalLength - 1) {
                return dfs(n - 1, k);
            }
          
            // If k is in the second half (after middle)
            // The second half is the reverse and invert of Sn-1
            // Find the corresponding position in Sn-1 and invert the result
            return dfs(n - 1, totalLength - k) ^ 1;
        };
      
        // Convert the bit value (0 or 1) to character ('0' or '1')
        return '0' + dfs(n, k);
    }
};