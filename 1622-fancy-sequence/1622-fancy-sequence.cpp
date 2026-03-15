const int MOD = 1e9 + 7;

/**
 * Node class for segment tree
 * Supports lazy propagation with addition and multiplication operations
 */
class Node {
public:
    Node* left;      // Left child node
    Node* right;     // Right child node
    int l;           // Left boundary of range
    int r;           // Right boundary of range
    int mid;         // Middle point of range
    long long v;     // Sum value of this range
    long long add;   // Lazy addition tag
    long long mul;   // Lazy multiplication tag

    Node(int l, int r) {
        this->l = l;
        this->r = r;
        this->mid = (l + r) >> 1;
        this->left = nullptr;
        this->right = nullptr;
        v = 0;
        add = 0;
        mul = 1;  // Initial multiplication factor is 1
    }
};

/**
 * Segment Tree with lazy propagation
 * Supports range addition, range multiplication, and range sum query
 */
class SegmentTree {
private:
    Node* root;

public:
    SegmentTree() {
        // Initialize tree with range [1, 100001]
        root = new Node(1, 1e5 + 1);
    }

    // Public interface for range addition
    void modifyAdd(int l, int r, int increment) {
        modifyAdd(l, r, increment, root);
    }

    // Recursive implementation of range addition
    void modifyAdd(int l, int r, int increment, Node* node) {
        if (l > r) return;
      
        // If current node's range is completely within [l, r]
        if (node->l >= l && node->r <= r) {
            // Update node value and lazy tag
            node->v = (node->v + (long long)(node->r - node->l + 1) * increment) % MOD;
            node->add = (node->add + increment) % MOD;
            return;
        }
      
        // Push down lazy tags before recursing
        pushdown(node);
      
        // Recurse on children if they overlap with [l, r]
        if (l <= node->mid) {
            modifyAdd(l, r, increment, node->left);
        }
        if (r > node->mid) {
            modifyAdd(l, r, increment, node->right);
        }
      
        // Update current node's value from children
        pushup(node);
    }

    // Public interface for range multiplication
    void modifyMul(int l, int r, int multiplier) {
        modifyMul(l, r, multiplier, root);
    }

    // Recursive implementation of range multiplication
    void modifyMul(int l, int r, int multiplier, Node* node) {
        if (l > r) return;
      
        // If current node's range is completely within [l, r]
        if (node->l >= l && node->r <= r) {
            // Update node value and lazy tags
            node->v = (node->v * multiplier) % MOD;
            node->add = (node->add * multiplier) % MOD;
            node->mul = (node->mul * multiplier) % MOD;
            return;
        }
      
        // Push down lazy tags before recursing
        pushdown(node);
      
        // Recurse on children if they overlap with [l, r]
        if (l <= node->mid) {
            modifyMul(l, r, multiplier, node->left);
        }
        if (r > node->mid) {
            modifyMul(l, r, multiplier, node->right);
        }
      
        // Update current node's value from children
        pushup(node);
    }

    // Public interface for range sum query
    int query(int l, int r) {
        return query(l, r, root);
    }

    // Recursive implementation of range sum query
    int query(int l, int r, Node* node) {
        if (l > r) return 0;
      
        // If current node's range is completely within [l, r]
        if (node->l >= l && node->r <= r) {
            return node->v;
        }
      
        // Push down lazy tags before querying children
        pushdown(node);
      
        int result = 0;
        // Query left child if it overlaps with [l, r]
        if (l <= node->mid) {
            result = (result + query(l, r, node->left)) % MOD;
        }
        // Query right child if it overlaps with [l, r]
        if (r > node->mid) {
            result = (result + query(l, r, node->right)) % MOD;
        }
      
        return result;
    }

    // Update parent node's value from its children
    void pushup(Node* node) {
        node->v = (node->left->v + node->right->v) % MOD;
    }

    // Push down lazy tags to children nodes
    void pushdown(Node* node) {
        // Create children nodes if they don't exist (dynamic segment tree)
        if (!node->left) {
            node->left = new Node(node->l, node->mid);
        }
        if (!node->right) {
            node->right = new Node(node->mid + 1, node->r);
        }
      
        // If there are pending lazy operations
        if (node->add != 0 || node->mul != 1) {
            long long addTag = node->add;
            long long mulTag = node->mul;
            Node* leftChild = node->left;
            Node* rightChild = node->right;
          
            // Apply multiplication first, then addition: new_val = old_val * mul + add
            // Update left child
            leftChild->v = (leftChild->v * mulTag + (leftChild->r - leftChild->l + 1) * addTag) % MOD;
            leftChild->add = (leftChild->add * mulTag + addTag) % MOD;
            leftChild->mul = (leftChild->mul * mulTag) % MOD;
          
            // Update right child
            rightChild->v = (rightChild->v * mulTag + (rightChild->r - rightChild->l + 1) * addTag) % MOD;
            rightChild->add = (rightChild->add * mulTag + addTag) % MOD;
            rightChild->mul = (rightChild->mul * mulTag) % MOD;
          
            // Clear parent's lazy tags
            node->add = 0;
            node->mul = 1;
        }
    }
};

/**
 * Fancy class that maintains a sequence with operations:
 * - append: add element to the end
 * - addAll: add value to all elements
 * - multAll: multiply all elements by a value
 * - getIndex: get element at specific index
 */
class Fancy {
private:
    int n;                  // Current number of elements
    SegmentTree* tree;      // Segment tree to maintain the sequence

public:
    Fancy() {
        n = 0;
        tree = new SegmentTree();
    }

    // Append a new value to the end of the sequence
    void append(int val) {
        ++n;
        // Add value at position n (1-indexed in segment tree)
        tree->modifyAdd(n, n, val);
    }

    // Add increment to all existing elements
    void addAll(int inc) {
        tree->modifyAdd(1, n, inc);
    }

    // Multiply all existing elements by m
    void multAll(int m) {
        tree->modifyMul(1, n, m);
    }

    // Get the value at index idx (0-indexed)
    int getIndex(int idx) {
        // Check if index is valid
        if (idx >= n) {
            return -1;
        }
        // Query position idx+1 (convert to 1-indexed)
        return tree->query(idx + 1, idx + 1);
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */