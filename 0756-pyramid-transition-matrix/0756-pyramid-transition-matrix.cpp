class Solution {
public:
    
    int allowedTopBlocks[7][7];
  
    // Memoization cache: maps state (currentRow + "." + nextRow) to whether it leads to success
    unordered_map<string, bool> memo;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // Initialize the allowed top blocks array
        memset(allowedTopBlocks, 0, sizeof(allowedTopBlocks));
      
        // Process each allowed triple and build the bitmask array
        // For pattern "XYZ", block Z can be placed on top of blocks X and Y
        for (auto& pattern : allowed) {
            int leftBlock = pattern[0] - 'A';
            int rightBlock = pattern[1] - 'A';
            int topBlock = pattern[2] - 'A';
          
            // Set the bit corresponding to topBlock in the bitmask
            allowedTopBlocks[leftBlock][rightBlock] |= (1 << topBlock);
        }
      
        // Start DFS with the bottom row and empty next row
        return buildPyramid(bottom, "");
    }

    bool buildPyramid(string& currentRow, string nextRow) {
        // Base case: pyramid is complete when we reach a single block at the top
        if (currentRow.size() == 1) {
            return true;
        }
      
        // Current row is fully processed, move to the next level
        if (nextRow.size() + 1 == currentRow.size()) {
            return buildPyramid(nextRow, "");
        }
      
        // Create a unique key for memoization
        string stateKey = currentRow + "." + nextRow;
        if (memo.count(stateKey)) {
            return memo[stateKey];
        }
      
        // Get the two adjacent blocks in the current row
        int leftBlockIndex = currentRow[nextRow.size()] - 'A';
        int rightBlockIndex = currentRow[nextRow.size() + 1] - 'A';
      
        // Get bitmask of allowed blocks that can be placed on top
        int possibleBlocks = allowedTopBlocks[leftBlockIndex][rightBlockIndex];
      
        // Try each possible block that can be placed on top
        for (int blockIndex = 0; blockIndex < 7; ++blockIndex) {
            // Check if this block is allowed (bit is set in the bitmask)
            if ((possibleBlocks >> blockIndex) & 1) {
                // Recursively try building with this block added to the next row
                if (buildPyramid(currentRow, nextRow + (char)(blockIndex + 'A'))) {
                    memo[stateKey] = true;
                    return true;
                }
            }
        }
      
        // No valid pyramid can be built from this state
        memo[stateKey] = false;
        return false;
    }
};