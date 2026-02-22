class Solution {
public:
    int binaryGap(int n) {
        int maxDistance = 0;
      
        // Initialize previous position to a large value (100) to handle edge case
        // where there's only one '1' bit (resulting in maxDistance = 0)
        int previousOnePosition = 100;
        int currentPosition = 0;
      
        // Iterate through each bit of n from right to left
        while (n != 0) {
            // Check if the current bit is 1
            if (n & 1) {
                // Calculate distance between current '1' and previous '1'
                maxDistance = max(maxDistance, currentPosition - previousOnePosition);
              
                // Update previous '1' position to current position
                previousOnePosition = currentPosition;
            }
          
            // Move to the next bit position
            ++currentPosition;
          
            // Right shift n by 1 to check the next bit
            n >>= 1;
        }
      
        return maxDistance;
    }
};