/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool isBalanced(TreeNode* root) {
        // Lambda function to calculate height and check balance simultaneously
        // Returns -1 if the tree is unbalanced, otherwise returns the height
        function<int(TreeNode*)> calculateHeight = [&](TreeNode* node) -> int {
            // Base case: empty node has height 0
            if (!node) {
                return 0;
            }
          
            // Recursively calculate the height of left subtree
            int leftHeight = calculateHeight(node->left);
          
            // Recursively calculate the height of right subtree
            int rightHeight = calculateHeight(node->right);
          
            // Check if any subtree is unbalanced or if current node violates balance condition
            // If left or right subtree is unbalanced (returns -1), or
            // if the height difference exceeds 1, mark as unbalanced
            if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
                return -1;  // Indicates unbalanced tree
            }
          
            // Return the height of current node (1 + maximum height of subtrees)
            return 1 + max(leftHeight, rightHeight);
        };
      
        // Tree is balanced if the height calculation doesn't return -1
        return calculateHeight(root) >= 0;
    }
};