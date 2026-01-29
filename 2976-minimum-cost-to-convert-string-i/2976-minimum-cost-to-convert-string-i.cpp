class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // Define a large value to represent infinity (no direct path)
        const int INF = 1 << 29;
      
        // Initialize adjacency matrix for 26 letters (a-z)
        // graph[i][j] represents the minimum cost to change from letter i to letter j
        int graph[26][26];
      
        // Initialize all distances to infinity, except diagonal (same letter) which is 0
        for (int i = 0; i < 26; ++i) {
            fill(begin(graph[i]), end(graph[i]), INF);
            graph[i][i] = 0;  // Cost to change a letter to itself is 0
        }

        // Build the graph from the given transformations
        for (int i = 0; i < original.size(); ++i) {
            int fromChar = original[i] - 'a';  // Convert char to index (0-25)
            int toChar = changed[i] - 'a';     // Convert char to index (0-25)
            int transformCost = cost[i];
          
            // Keep the minimum cost if there are multiple transformations for the same pair
            graph[fromChar][toChar] = min(graph[fromChar][toChar], transformCost);
        }

        // Apply Floyd-Warshall algorithm to find shortest paths between all pairs
        for (int intermediate = 0; intermediate < 26; ++intermediate) {
            for (int start = 0; start < 26; ++start) {
                for (int end = 0; end < 26; ++end) {
                    // Update shortest path from start to end through intermediate node
                    graph[start][end] = min(graph[start][end], 
                                           graph[start][intermediate] + graph[intermediate][end]);
                }
            }
        }

        // Calculate the total minimum cost to transform source string to target string
        long long totalCost = 0;
        int stringLength = source.length();
      
        for (int i = 0; i < stringLength; ++i) {
            int sourceChar = source[i] - 'a';  // Convert to index (0-25)
            int targetChar = target[i] - 'a';  // Convert to index (0-25)
          
            // Only need transformation if characters are different
            if (sourceChar != targetChar) {
                // Check if transformation is possible
                if (graph[sourceChar][targetChar] >= INF) {
                    return -1;  // Impossible to transform this character
                }
                totalCost += graph[sourceChar][targetChar];
            }
        }
      
        return totalCost;
    }
};