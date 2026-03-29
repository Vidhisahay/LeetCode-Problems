class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // Create a 2D array to track character frequency differences
        // charFrequency[0] tracks characters at even positions (0, 2, 4, ...)
        // charFrequency[1] tracks characters at odd positions (1, 3, 5, ...)
        vector<vector<int>> charFrequency(2, vector<int>(26, 0));
      
        // Process each character in both strings
        for (int i = 0; i < s1.size(); ++i) {
            int positionParity = i & 1;  // 0 for even indices, 1 for odd indices
          
            // Increment count for character from s1 at this position parity
            ++charFrequency[positionParity][s1[i] - 'a'];
          
            // Decrement count for character from s2 at this position parity
            --charFrequency[positionParity][s2[i] - 'a'];
        }
      
        // Check if all character frequencies are balanced (should be 0)
        // If any frequency is non-zero, strings cannot be made equal
        for (int charIndex = 0; charIndex < 26; ++charIndex) {
            if (charFrequency[0][charIndex] != 0 || charFrequency[1][charIndex] != 0) {
                return false;
            }
        }
      
        // All frequencies are balanced, strings can be made equal
        return true;
    }
};
