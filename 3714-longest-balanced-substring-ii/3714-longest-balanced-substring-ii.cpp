class Solution {
public:
    int longestBalanced(string s) {
        // Return the maximum of all three cases: 1, 2, or 3 distinct characters.
        return max({calc1(s), 
                    calc2(s, 'a', 'b'), calc2(s, 'b', 'c'), calc2(s, 'a', 'c'), 
                    calc3(s)});
    }

private:
    // Case 1: Longest substring with exactly 1 distinct character (e.g., "aaaa")
    int calc1(const string& s) {
        int res = 0, i = 0, n = s.size();
        while (i < n) {
            int j = i + 1;
            while (j < n && s[j] == s[i]) ++j;
            res = max(res, j - i);
            i = j;
        }
        return res;
    }

    // Case 2: Longest substring with exactly 2 distinct characters (e.g., "aabb")
    int calc2(const string& s, char a, char b) {
        int res = 0, i = 0, n = s.size();
        while (i < n) {
            // Skip characters that aren't 'a' or 'b'
            while (i < n && s[i] != a && s[i] != b) ++i;
            
            unordered_map<int, int> pos;
            pos[0] = i - 1; // Base case for difference 0
            int diff = 0;
            
            // Process a segment containing only 'a's and 'b's
            while (i < n && (s[i] == a || s[i] == b)) {
                diff += (s[i] == a) ? 1 : -1;
                if (pos.count(diff)) {
                    res = max(res, i - pos[diff]);
                } else {
                    pos[diff] = i;
                }
                i++;
            }
        }
        return res;
    }

    // Hash helper for the pair of differences in Case 3
    static long long encode(int x, int y) {
        return ((long long)(x + 100005) << 22) | (long long)(y + 100005);
    }

    // Case 3: Longest substring with exactly 3 distinct characters (e.g., "abcabc")
    int calc3(const string& s) {
        unordered_map<long long, int> pos;
        pos[encode(0, 0)] = -1;
        int cnt[3] = {0, 0, 0};
        int res = 0;
        
        for (int i = 0; i < (int)s.size(); i++) {
            cnt[s[i] - 'a']++;
            // A substring is balanced if (a-b) and (b-c) remain the same
            int diff1 = cnt[0] - cnt[1];
            int diff2 = cnt[1] - cnt[2];
            long long key = encode(diff1, diff2);
            
            if (pos.count(key)) {
                res = max(res, i - pos[key]);
            } else {
                pos[key] = i;
            }
        }
        return res;
    }
};