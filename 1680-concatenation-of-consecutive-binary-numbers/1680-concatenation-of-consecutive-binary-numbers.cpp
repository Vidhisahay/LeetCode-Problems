class Solution {
public:
    int concatenatedBinary(int n) {
        // Define modulo constant for preventing integer overflow
        const int MOD = 1000000007;
      
        // Initialize result variable to store the concatenated binary value
        long result = 0;
      
        // Iterate through all numbers from 1 to n
        for (int i = 1; i <= n; ++i) {
            // Calculate the number of bits in current number i
            // __builtin_clz(i) returns the number of leading zeros in 32-bit representation
            // So (32 - __builtin_clz(i)) gives us the actual bit length of i
            int bitLength = 32 - __builtin_clz(i);
          
            // Left shift the current result by bitLength positions to make room for i
            // Then use bitwise OR to append i to the result
            // Apply modulo to keep the result within bounds
            result = ((result << bitLength) | i) % MOD;
        }
      
        // Return the final concatenated binary value as an integer
        return static_cast<int>(result);
    }
};