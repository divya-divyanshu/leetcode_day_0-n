class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    bool solve(Node* root){
        if(root == nullptr) return true;
        if(!root->left && !root->right){
            return true;
        }
        int left = 0, right = 0;
        if(root->left) left = root->left->data;
        if(root->right) right = root->right->data;
        if(left+right != root->data) return false;
        
        return solve(root->left) &&  solve(root->right);
        
        
        
    }
    int isSumProperty(Node *root) {
        // Add your code here
         if (solve(root)) return 1;
         return 0;
    }
};