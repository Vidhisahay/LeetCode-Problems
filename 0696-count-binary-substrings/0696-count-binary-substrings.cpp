class Solution {
public:
    int countBinarySubstrings(string s) {
        int currentIndex = 0;
        int stringLength = s.size();
        vector<int> groupSizes;  // Store the size of consecutive groups of same characters
      
        // Count consecutive groups of 0s and 1s
        while (currentIndex < stringLength) {
            int groupCount = 1;  // Count of current group
          
            // Count consecutive same characters
            while (currentIndex + 1 < stringLength && s[currentIndex + 1] == s[currentIndex]) {
                ++groupCount;
                ++currentIndex;
            }
          
            // Store the group size
            groupSizes.push_back(groupCount);
            ++currentIndex;
        }
      
        int result = 0;
      
        // For each adjacent pair of groups, we can form min(group1, group2) valid substrings
        // Example: "0011" has groups [2,2], we can form min(2,2) = 2 substrings: "01" and "0011"
        for (int i = 1; i < groupSizes.size(); ++i) {
            result += min(groupSizes[i - 1], groupSizes[i]);
        }
      
        return result;
    }
};
