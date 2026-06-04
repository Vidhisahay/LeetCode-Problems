#include <string>

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total_waviness = 0;
        
        for (int i = num1; i <= num2; ++i) {
            std::string s = std::to_string(i);
            if (s.length() < 3) continue;
            
            for (size_t j = 1; j < s.length() - 1; ++j) {
                if ((s[j] > s[j - 1] && s[j] > s[j + 1]) || // Peak
                    (s[j] < s[j - 1] && s[j] < s[j + 1])) {  // Valley
                    total_waviness++;
                }
            }
        }
        return total_waviness;
    }
};