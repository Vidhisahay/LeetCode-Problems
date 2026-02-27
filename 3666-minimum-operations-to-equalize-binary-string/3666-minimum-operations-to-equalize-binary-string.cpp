class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int z0 = 0;
        for (char c : s) if (c == '0') z0++;
        if (z0 == 0) return 0;

        vector<int> dist(n + 1, -1);
        queue<int> q;

        dist[z0] = 0;
        q.push(z0);

        // parents[0] for even states, parents[1] for odd states
        // This acts as a DSU to jump over already visited nodes in O(1)
        vector<int> parent_even(n + 3), parent_odd(n + 3);
        iota(parent_even.begin(), parent_even.end(), 0);
        iota(parent_odd.begin(), parent_odd.end(), 0);

        auto find = [&](auto& self, vector<int>& p, int i) -> int {
            return p[i] == i ? i : p[i] = self(self, p, p[i]);
        };

        // Mark initial_z as visited in its parity set
        if (z0 % 2 == 0) parent_even[z0] = z0 + 2;
        else parent_odd[z0] = z0 + 2;

        while (!q.empty()) {
            int z = q.front();
            q.pop();

            if (z == 0) return dist[z];

            // Range [L, R] of zero-counts reachable by flipping i zeros
            int L = abs(z - k);
            int R = n - abs(n - (z + k));

            // Select the correct jump-table based on parity
            auto& p = (L % 2 == 0) ? parent_even : parent_odd;
            
            for (int next_z = find(find, p, L); next_z <= R; next_z = find(find, p, next_z)) {
                if (dist[next_z] == -1) {
                    dist[next_z] = dist[z] + 1;
                    if (next_z == 0) return dist[next_z];
                    q.push(next_z);
                }
                // Jump this node next time
                p[next_z] = find(find, p, next_z + 2);
            }
        }

        return -1;
    }
};