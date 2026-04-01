class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
      
        // Create an index array to track original positions after sorting
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
      
        // Stack to store indices of robots moving right
        stack<int> rightMovingRobots;
      
        // Sort indices based on robot positions (left to right on the line)
        sort(indices.begin(), indices.end(), [&](int i, int j) { 
            return positions[i] < positions[j]; 
        });
      
        // Process robots from left to right based on their positions
        for (int currentIndex : indices) {
            if (directions[currentIndex] == 'R') {
                // Robot moving right, add to stack for potential collision
                rightMovingRobots.push(currentIndex);
            } else {
                // Robot moving left, check for collisions with right-moving robots
                while (!rightMovingRobots.empty() && healths[currentIndex] > 0) {
                    int rightRobotIndex = rightMovingRobots.top();
                    rightMovingRobots.pop();
                  
                    if (healths[rightRobotIndex] > healths[currentIndex]) {
                        // Right-moving robot survives with reduced health
                        healths[rightRobotIndex] -= 1;
                        healths[currentIndex] = 0;
                        rightMovingRobots.push(rightRobotIndex);
                    } else if (healths[rightRobotIndex] < healths[currentIndex]) {
                        // Left-moving robot survives with reduced health
                        healths[currentIndex] -= 1;
                        healths[rightRobotIndex] = 0;
                    } else {
                        // Both robots have equal health and destroy each other
                        healths[currentIndex] = 0;
                        healths[rightRobotIndex] = 0;
                    }
                }
            }
        }
      
        // Collect surviving robots' healths in original order
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }
      
        return result;
    }
};