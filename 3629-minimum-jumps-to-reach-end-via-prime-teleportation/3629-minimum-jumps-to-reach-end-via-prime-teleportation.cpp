
// Sieve precomputation for Smallest Prime Factor (SPF)
const int MAX_VAL = 1e6 + 1;
int spf[MAX_VAL];

void precompute_sieve() {
    for (int i = 2; i < MAX_VAL; ++i) {
        if (spf[i] == 0) { // i is prime
            for (int j = i; j < MAX_VAL; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
}

class Solution {
public:
    int minJumps(vector<int>& nums) {
        // Run sieve once (can be moved outside if running multiple test cases)
        static bool sieved = false;
        if (!sieved) {
            precompute_sieve();
            sieved = true;
        }

        int n = nums.size();
        // Map prime p -> list of indices j where nums[j] is divisible by p
        unordered_map<int, vector<int>> prime_to_indices;
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            while (val > 1) {
                int p = spf[val];
                prime_to_indices[p].push_back(i);
                while (val % p == 0) val /= p;
            }
        }

        queue<int> q;
        vector<int> dist(n, -1);
        vector<bool> prime_used(MAX_VAL, false);

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == n - 1) return dist[curr];

            // 1. Adjacent Step: Left/Right
            for (int neighbor : {curr - 1, curr + 1}) {
                if (neighbor >= 0 && neighbor < n && dist[neighbor] == -1) {
                    dist[neighbor] = dist[curr] + 1;
                    q.push(neighbor);
                }
            }

            // 2. Prime Teleportation: Only if current value is prime
            int p = nums[curr];
            if (p >= 2 && spf[p] == p && !prime_used[p]) {
                prime_used[p] = true;
                for (int next_idx : prime_to_indices[p]) {
                    if (dist[next_idx] == -1) {
                        dist[next_idx] = dist[curr] + 1;
                        q.push(next_idx);
                    }
                }
                // Optimization: Clear to avoid redundant scans
                prime_to_indices[p].clear();
            }
        }

        return -1;
    }
};
