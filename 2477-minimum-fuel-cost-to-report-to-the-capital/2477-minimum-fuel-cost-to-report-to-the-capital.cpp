class Solution {
public:
    long long fuel = 0;

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }

        dfs(0, -1, adj, seats);
        return fuel;
    }

private:
    long long dfs(int u, int p, vector<vector<int>>& adj, int seats) {
        long long people = 1; // Each city starts with 1 representative
        for (int v : adj[u]) {
            if (v != p) {
                people += dfs(v, u, adj, seats);
            }
        }

        // If not at capital, calculate fuel to move 'people' to the parent node
        if (u != 0) {
            // (people + seats - 1) / seats is equivalent to ceil(people / seats)
            fuel += (people + seats - 1) / seats;
        }
        return people;
    }
};