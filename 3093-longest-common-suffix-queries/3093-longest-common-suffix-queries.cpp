class Solution {
private:
    struct TrieNode {
        int children[26];
        int best_index;

        TrieNode() {
            // Initialize all children paths to -1 (null/empty)
            fill(begin(children), end(children), -1);
            best_index = -1;
        }
    };

    vector<TrieNode> trie;

    // Helper to check if string at index i is a better candidate than index j
    bool is_better(int i, int j, const vector<string>& wordsContainer) {
        if (j == -1) return true;
        if (wordsContainer[i].length() != wordsContainer[j].length()) {
            return wordsContainer[i].length() < wordsContainer[j].length();
        }
        return i < j;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.clear();
        // Allocate space upfront: Root node + maximum potential character nodes
        trie.reserve(500005); 
        trie.emplace_back(); // Insert root node at index 0

        // Step 1: Find the global fallback index (0 common suffix match)
        int global_best_idx = 0;
        for (int i = 1; i < wordsContainer.size(); ++i) {
            if (wordsContainer[i].length() < wordsContainer[global_best_idx].length()) {
                global_best_idx = i;
            }
        }
        trie[0].best_index = global_best_idx;

        // Step 2: Build the Trie by inserting strings in reverse order
        for (int i = 0; i < wordsContainer.size(); ++i) {
            const string& word = wordsContainer[i];
            int curr_node_idx = 0;

            for (int j = word.length() - 1; j >= 0; --j) {
                int char_idx = word[j] - 'a';
                
                if (trie[curr_node_idx].children[char_idx] == -1) {
                    trie[curr_node_idx].children[char_idx] = trie.size();
                    trie.emplace_back();
                }
                
                curr_node_idx = trie[curr_node_idx].children[char_idx];
                
                // Track the optimal index matching this suffix sequence
                if (is_better(i, trie[curr_node_idx].best_index, wordsContainer)) {
                    trie[curr_node_idx].best_index = i;
                }
            }
        }

        // Step 3: Process the query strings
        vector<int> ans;
        ans.reserve(wordsQuery.size());

        for (const string& query : wordsQuery) {
            int curr_node_idx = 0;
            
            for (int j = query.length() - 1; j >= 0; --j) {
                int char_idx = query[j] - 'a';
                if (trie[curr_node_idx].children[char_idx] != -1) {
                    curr_node_idx = trie[curr_node_idx].children[char_idx];
                } else {
                    break; // Stop climbing if the common suffix chain breaks
                }
            }
            ans.push_back(trie[curr_node_idx].best_index);
        }

        return ans;
    }
};
