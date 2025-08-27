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
    int rightHeight(TreeNode* node){
        int cnt = 0;
        while(node){
            cnt++;
            node = node->right;
        }
        return cnt;
    }
    int leftHeight(TreeNode* node){
        int cnt = 0;
        while(node){
            cnt++;
            node = node->left;
        }
        return cnt;
    }
    int fn(TreeNode* root){
        if(root == nullptr) return 0;
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if(lh == rh) return pow(2, lh)-1;
        return 1 + fn(root->left) + fn(root->right);
    }
    int countNodes(TreeNode* root) {

        return fn(root); 
        
    }
};