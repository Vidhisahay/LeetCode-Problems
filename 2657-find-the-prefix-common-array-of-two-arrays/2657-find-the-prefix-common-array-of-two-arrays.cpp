class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> result(n);
      
        // Frequency arrays to track occurrences of each number (1 to n)
        // in prefixes of A and B respectively
        vector<int> frequencyA(n + 1, 0);  // Index 0 unused, 1 to n for values
        vector<int> frequencyB(n + 1, 0);
      
        // Process each position from 0 to n-1
        for (int i = 0; i < n; ++i) {
            // Increment frequency for current elements
            ++frequencyA[A[i]];
            ++frequencyB[B[i]];
          
            // Count common elements in current prefixes
            // A number is common if it appears in both prefixes
            // The count of common occurrences is the minimum of its frequencies
            for (int value = 1; value <= n; ++value) {
                result[i] += min(frequencyA[value], frequencyB[value]);
            }
        }
      
        return result;
    }
};
