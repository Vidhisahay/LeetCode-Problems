class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        // Safe infinity for path costs within int range
        const int INF = 2e9;
        
        // Adjacency list: node -> list of {neighbor, cost}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            // Original edge costs w
            adj[u].push_back({v, w});
            // Reversed edge costs 2 * w
            adj[v].push_back({u, 2 * w});
        }
        
        // Distance array initialized to INF
        vector<int> dist(n, INF);
        dist[0] = 0;
        
        // Min-priority queue: {cost, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            int current_cost = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            // Skip processing if a cheaper path was already found
            if (current_cost > dist[u]) continue;
            
            // Early exit if we reach the target node
            if (u == n - 1) return current_cost;
            
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int edge_weight = neighbor.second;
                
                if (dist[u] + edge_weight < dist[v]) {
                    dist[v] = dist[u] + edge_weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        // Return -1 if node n-1 is unreachable
        return (dist[n - 1] == INF) ? -1 : dist[n - 1];
    }
};
