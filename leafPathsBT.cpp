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
    void fn(TreeNode* node, vector<string>&ans, vector<int>&temp){
        if(node == nullptr) return;
        
        temp.push_back(node->val);
        
        if(node->left == nullptr && node->right == nullptr){
            int n = temp.size();
            string tempStr = "";
            for(int i  = 0; i<n-1; i++){
                tempStr += to_string(temp[i]);
                tempStr += "->";
            }
            tempStr += to_string(temp[n-1]);
            ans.push_back(tempStr);
        } 
        
        fn(node->left, ans, temp);
        fn(node->right, ans, temp);
        
        temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        vector<int>temp;
        if(root == nullptr) return ans;
        fn(root, ans, temp);
        return ans;
    }
};