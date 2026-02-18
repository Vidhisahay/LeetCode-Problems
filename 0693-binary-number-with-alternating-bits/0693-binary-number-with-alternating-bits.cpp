class Solution {
public:
    bool hasAlternatingBits(int n) {
        // Initialize previous bit to -1 (invalid value) for first comparison
        int previousBit = -1;
      
        // Process each bit of the number from right to left
        while (n > 0) {
            // Extract the least significant bit (rightmost bit)
            int currentBit = n & 1;
          
            // Check if current bit is same as previous bit
            // If they are the same, bits are not alternating
            if (previousBit == currentBit) {
                return false;
            }
          
            // Update previous bit for next iteration
            previousBit = currentBit;
          
            // Right shift to process the next bit
            n >>= 1;
        }
      
        // All bits processed successfully with alternating pattern
        return true;
    }
};