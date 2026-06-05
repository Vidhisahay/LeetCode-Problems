#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
private:
    // Max digits for 10^15 is ~16, use 20 to be safe
    long long dp_w[20][11][11][2][2];
    long long dp_c[20][11][11][2][2];
    string s;

    // Helper pair structure to return (waviness, count)
    pair<long long, long long> dfs(int i, int prev, int prev2, bool is_limit, bool is_num) {
        if (i == s.length()) {
            return {0, is_num ? 1 : 0};
        }
        
        // Map -1 to index 10 for safe array bounds
        int p1_idx = (prev == -1) ? 10 : prev;
        int p2_idx = (prev2 == -1) ? 10 : prev2;

        // Check cache using all 5 dimensions
        if (dp_w[i][p1_idx][p2_idx][is_limit][is_num] != -1) {
            return {dp_w[i][p1_idx][p2_idx][is_limit][is_num], dp_c[i][p1_idx][p2_idx][is_limit][is_num]};
        }

        long long total_w = 0, total_c = 0;
        int up = is_limit ? (s[i] - '0') : 9;

        // Option 1: Handle leading zero skip
        if (!is_num) {
            auto [w, c] = dfs(i + 1, -1, -1, false, false);
            total_w += w;
            total_c += c;
        }

        // Option 2: Place valid non-leading digit
        int down = is_num ? 0 : 1;
        for (int d = down; d <= up; ++d) {
            bool next_is_limit = is_limit && (d == up);
            long long w_contrib = 0;
            
            // Check if the previous digit forms a peak or a valley
            if (is_num && prev != -1 && prev2 != -1) {
                if ((prev > prev2 && prev > d) || (prev < prev2 && prev < d)) {
                    w_contrib = 1;
                }
            }

            auto [w, c] = dfs(i + 1, d, prev, next_is_limit, true);
            total_w += w + w_contrib * c;
            total_c += c;
        }

        // Cache the calculated state using all 5 dimensions correctly
        dp_w[i][p1_idx][p2_idx][is_limit][is_num] = total_w;
        dp_c[i][p1_idx][p2_idx][is_limit][is_num] = total_c;
        
        return {total_w, total_c};
    }

    long long solve(long long num) {
        if (num <= 0) return 0;
        s = to_string(num);
        memset(dp_w, -1, sizeof(dp_w));
        memset(dp_c, -1, sizeof(dp_c));
        return dfs(0, -1, -1, true, false).first;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
