class Solution {
public:
    
    bool judgeCircle(string moves) {
        // Initialize coordinates to track robot's position
        int xCoordinate = 0;
        int yCoordinate = 0;
      
        // Process each move command
        for (char move : moves) {
            switch (move) {
                case 'U':  // Move up
                    yCoordinate++;
                    break;
                case 'D':  // Move down
                    yCoordinate--;
                    break;
                case 'L':  // Move left
                    xCoordinate--;
                    break;
                case 'R':  // Move right
                    xCoordinate++;
                    break;
            }
        }
      
        // Check if robot returned to origin
        return (xCoordinate == 0 && yCoordinate == 0);
    }
};