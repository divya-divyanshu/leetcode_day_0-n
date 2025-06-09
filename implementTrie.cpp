class Trie {
    
public:
    class TrieNode{
        public:
        TrieNode* child[26];
        bool isleaf;

        TrieNode(){
            isleaf = false;
            for(int i = 0; i < 26; i++) child[i] = nullptr;
        }
        
    };
    TrieNode* root = new TrieNode();

    
    
    void insert(string word) {
        TrieNode* cur = root;

        for(char ch: word){
            int ind = ch-'a';
            if(cur->child[ind] == nullptr){
                TrieNode* newNode = new TrieNode();
                cur->child[ind] = newNode;
            }

            cur = cur->child[ind];
        }

        cur->isleaf = true;
        
    }
    
    bool search(string word) {

        TrieNode* cur = root;
        for(char ch:word){
            int ind = ch-'a';
            if(cur->child[ind] != nullptr){
                cur = cur->child[ind];
            }
            else return false;
        }

        if(cur->isleaf == true) return true;
        return false;
        
    }
    
    bool startsWith(string word) {
        TrieNode* cur = root;
        for(char ch:word){
            int ind = ch-'a';
            if(cur->child[ind] != nullptr){
                cur = cur->child[ind];
            }
            else return false;
        }

        // if(cur->isleaf == true) return true;
        // return false;
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */