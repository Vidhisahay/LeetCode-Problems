class Solution {
public:
    int minPartitions(string n) {
        // Initialize the maximum digit found so far
        int maxDigit = 0;
      
        // Iterate through each character in the string
        for (char& digit : n) {
            // Convert character to integer and update maximum
            maxDigit = max(maxDigit, digit - '0');
        }
      
        // The minimum partitions needed equals the largest digit
        // This works because we can form the number using deci-binary numbers
        // (numbers with only 0s and 1s), and the largest digit determines
        // how many such numbers we need to sum up to
        return maxDigit;
    }
};