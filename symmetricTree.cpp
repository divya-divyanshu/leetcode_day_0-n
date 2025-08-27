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
    bool isSmfn(TreeNode* left, TreeNode* right){
        if(left == nullptr || right == nullptr) return (left == right);
        if(left->val != right->val) return false;

        return isSmfn(left->left, right->right) 
        && isSmfn(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        // if(root == nullptr) return true;
        return isSmfn(root->left, root->right);
    }
};