class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int nodeCount = roads.size() + 1;
      
        // Build adjacency list representation of the tree
        vector<vector<int>> adjacencyList(nodeCount);
        for (const auto& road : roads) {
            int cityA = road[0];
            int cityB = road[1];
            adjacencyList[cityA].push_back(cityB);
            adjacencyList[cityB].push_back(cityA);
        }
      
        // Variable to store the total fuel cost
        long long totalFuelCost = 0;
      
        // DFS function to calculate subtree sizes and fuel costs
        // Returns the number of representatives in the subtree rooted at 'current'
        function<int(int, int)> dfs = [&](int current, int parent) -> int {
            // Each city starts with 1 representative
            int subtreeSize = 1;
          
            // Traverse all neighboring cities
            for (int neighbor : adjacencyList[current]) {
                // Skip the parent to avoid revisiting
                if (neighbor != parent) {
                    // Recursively calculate the subtree size
                    int neighborSubtreeSize = dfs(neighbor, current);
                  
                    // Calculate cars needed to transport representatives from neighbor to current
                    // Using ceiling division: (representatives + seats - 1) / seats
                    totalFuelCost += (neighborSubtreeSize + seats - 1) / seats;
                  
                    // Add representatives from the neighbor's subtree
                    subtreeSize += neighborSubtreeSize;
                }
            }
          
            return subtreeSize;
        };
      
        // Start DFS from the capital (node 0) with no parent (-1)
        dfs(0, -1);
      
        return totalFuelCost;
    }
};
