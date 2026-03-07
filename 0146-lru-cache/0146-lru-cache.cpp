class LRUCache {
private:
    // Doubly linked list node structure
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
      
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
  
    int currentSize;                           // Current number of elements in cache
    int maxCapacity;                           // Maximum capacity of cache
    Node* dummyHead;                           // Dummy head node for easier list manipulation
    Node* dummyTail;                           // Dummy tail node for easier list manipulation
    unordered_map<int, Node*> keyToNode;      // Hash map for O(1) key lookup
  
    // Remove a node from its current position in the doubly linked list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
  
    // Add a node right after the dummy head (making it the most recently used)
    void addToHead(Node* node) {
        node->next = dummyHead->next;
        node->prev = dummyHead;
        dummyHead->next->prev = node;
        dummyHead->next = node;
    }
  
public:
    // Initialize LRU cache with given capacity
    LRUCache(int capacity) : currentSize(0), maxCapacity(capacity) {
        // Create dummy head and tail nodes to simplify edge cases
        dummyHead = new Node(0, 0);
        dummyTail = new Node(0, 0);
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
  
    // Get value for given key, return -1 if not found
    // Move accessed node to head (mark as most recently used)
    int get(int key) {
        // Check if key exists in cache
        if (keyToNode.find(key) == keyToNode.end()) {
            return -1;
        }
      
        // Move node to head (mark as most recently used)
        Node* node = keyToNode[key];
        removeNode(node);
        addToHead(node);
      
        return node->value;
    }
  
    // Insert or update key-value pair in cache
    void put(int key, int value) {
        // Case 1: Key already exists - update value and move to head
        if (keyToNode.find(key) != keyToNode.end()) {
            Node* node = keyToNode[key];
            removeNode(node);
            node->value = value;
            addToHead(node);
        } 
        // Case 2: New key - create new node and add to cache
        else {
            Node* newNode = new Node(key, value);
            keyToNode[key] = newNode;
            addToHead(newNode);
            currentSize++;
          
            // If capacity exceeded, remove least recently used node (tail)
            if (currentSize > maxCapacity) {
                Node* lruNode = dummyTail->prev;
                keyToNode.erase(lruNode->key);
                removeNode(lruNode);
                delete lruNode;  // Free memory
                currentSize--;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */