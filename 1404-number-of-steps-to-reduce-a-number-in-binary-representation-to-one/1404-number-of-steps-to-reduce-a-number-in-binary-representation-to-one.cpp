class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        bool hasCarry = false;
      
        // Process binary string from right to left (least significant bit first)
        // Stop before index 0 (most significant bit)
        for (int i = s.size() - 1; i > 0; --i) {
            char currentBit = s[i];
          
            // Handle carry from previous addition
            if (hasCarry) {
                if (currentBit == '0') {
                    // 0 + carry = 1, no carry forward
                    currentBit = '1';
                    hasCarry = false;
                } else {
                    // 1 + carry = 0, carry forward continues
                    currentBit = '0';
                }
            }
          
            // If current bit is 1, we need to add 1 (make it even)
            // This creates a carry for the next iteration
            if (currentBit == '1') {
                ++steps;  // Step for adding 1
                hasCarry = true;
            }
          
            // Always need one step for division by 2 (right shift)
            ++steps;
        }
      
        // If there's still a carry after processing all bits,
        // it means we need one more division step
        if (hasCarry) {
            ++steps;
        }
      
        return steps;
    }
};
