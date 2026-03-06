class Solution {
public:
    
    bool checkOnesSegment(string s) {
        // Check if pattern "01" exists in the string
        // If "01" is not found (returns string::npos), all '1's are contiguous
        return s.find("01") == string::npos;
    }
};