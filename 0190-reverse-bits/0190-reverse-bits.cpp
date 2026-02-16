class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
      
        // Process each bit position (up to 32 bits)
        // Early termination when n becomes 0 (optimization)
        for (int i = 0; i < 32 && n != 0; ++i) {
            // Extract the least significant bit (LSB) of n
            // Place it at position (31 - i) in the result
            result |= (n & 1) << (31 - i);
          
            // Shift n right by 1 to process the next bit
            n >>= 1;
        }
      
        return result;
    }
};