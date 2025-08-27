class Solution {
  public:
    void fn(Node* node, vector<vector<int>>&ans, vector<int>&temp){
        if(node == nullptr) return;
        
        temp.push_back(node->data);
        
        if(node->left == nullptr && node->right == nullptr){
            ans.push_back(temp);
        } 
        
        fn(node->left, ans, temp);
        fn(node->right, ans, temp);
        
        temp.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>ans;
        vector<int>temp;
        if(!root) return ans;
        fn(root, ans, temp);
        return ans;
        
    }
};