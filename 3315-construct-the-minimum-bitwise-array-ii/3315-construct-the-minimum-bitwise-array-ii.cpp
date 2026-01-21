class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;
      
        for (int num : nums) {
            // Special case: when num is 2, no valid answer exists
            // This is because 2 in binary is 10, and we need ans | (ans + 1) = 2
            // No such ans exists that satisfies this condition
            if (num == 2) {
                result.push_back(-1);
            } else {
                // Find the minimum value ans such that ans | (ans + 1) = num
                // Strategy: Find the first 0 bit starting from position 1
                // Then flip the bit at position (i-1)
                for (int bitPos = 1; bitPos < 32; ++bitPos) {
                    // Check if the bit at position bitPos is 0
                    // Using XOR with 1 to check if bit is 0 (0 ^ 1 = 1, 1 ^ 1 = 0)
                    if (((num >> bitPos) & 1) ^ 1) {
                        // Found first 0 bit at position bitPos
                        // Flip the bit at position (bitPos - 1) to get the answer
                        result.push_back(num ^ (1 << (bitPos - 1)));
                        break;
                    }
                }
            }
        }
      
        return result;
    }
};