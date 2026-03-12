class Solution {
public:
    struct Edge {
        int u, v, s, must;
    };

    struct DSU {
        vector<int> parent;
        int count;
        DSU(int n) : parent(n + 1), count(n) {
            for (int i = 0; i <= n; i++) parent[i] = i;
        }
        int find(int i) {
            return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
        }
        bool unite(int i, int j) {
            int root_i = find(i), root_j = find(j);
            if (root_i != root_j) {
                parent[root_i] = root_j;
                count--;
                return true;
            }
            return false;
        }
    };

    bool canAchieve(int mid, int n, int k, const vector<Edge>& mandatory, const vector<Edge>& optional) {
        DSU dsu(n);
        int edgesUsed = 0;

        // 1. Mandatory Edges: Must meet target and cannot form cycles
        for (const auto& e : mandatory) {
            if (e.s < mid) return false;
            if (!dsu.unite(e.u, e.v)) return false;
            edgesUsed++;
        }

        // 2. Free Optional Edges: Already meet target without upgrades
        for (const auto& e : optional) {
            if (e.s >= mid) {
                if (dsu.unite(e.u, e.v)) edgesUsed++;
            }
        }

        // 3. Upgrade-Required Edges: Need 1 upgrade to meet target
        int upgradesSpent = 0;
        for (const auto& e : optional) {
            if (e.s < mid && 2 * e.s >= mid) {
                if (upgradesSpent < k && dsu.find(e.u) != dsu.find(e.v)) {
                    dsu.unite(e.u, e.v);
                    upgradesSpent++;
                    edgesUsed++;
                }
            }
        }

        return edgesUsed == n - 1 && dsu.count == 1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<Edge> mandatory, optional;
        int low = 0, high = 0;

        for (const auto& e : edges) {
            if (e[3] == 1) {
                mandatory.push_back({e[0], e[1], e[2], 1});
                high = max(high, e[2]);
            } else {
                optional.push_back({e[0], e[1], e[2], 0});
                high = max(high, 2 * e[2]);
            }
        }

        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canAchieve(mid, n, k, mandatory, optional)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};
