class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        
        for (const string& q : queries) {
            for (const string& d : dictionary) {
                int diff = 0;
                // Since words are the same length, compare character by character
                for (int i = 0; i < q.length(); ++i) {
                    if (q[i] != d[i]) {
                        diff++;
                    }
                    // Optimization: if differences exceed 2, this dictionary word fails
                    if (diff > 2) break; 
                }
                
                // If we found a word within 2 edits, add it and stop checking dictionary
                if (diff <= 2) {
                    result.push_back(q);
                    break;
                }
            }
        }
        
        return result;
    }
};
