struct node {
    node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    node* get(char ch) {
        return links[ch - 'a'];
    }
    void put(char ch, node* newNode) {
        links[ch - 'a'] = newNode;
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    node* root;
public:
    Trie() {
        root = new node();
        // Initialize all links to nullptr
        for (int i = 0; i < 26; i++)
            root->links[i] = NULL;
    }

    void insert(string word) {
        node* newNode = root;
        for (int i = 0; i < word.size(); i++) {
            if (!newNode->containsKey(word[i])) {
                newNode->put(word[i], new node());
                // initialize new node’s links
                for (int j = 0; j < 26; j++)
                    newNode->get(word[i])->links[j] = NULL;
            }
            newNode = newNode->get(word[i]);
        }
        newNode->setEnd();
    }

    bool checkIfPrefixExists(string word) {
        node* newNode = root;
        for (int i = 0; i < word.size(); i++) {
            if (!newNode->containsKey(word[i])) return false;

            newNode = newNode->get(word[i]);
            if (newNode->isEnd() == false) return false;
        }
        return true;
    }
};

class Solution {
public:
    string longestValidWord(vector<string>& words) {
        Trie trie;
        for (auto& it : words) trie.insert(it);

        string ans = "";
        for (auto& it : words) {
            if (trie.checkIfPrefixExists(it)) {
                if (it.size() > ans.size() || (it.size() == ans.size() && it < ans))
                    ans = it;
            }
        }
        return ans;
    }
};
