/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* a, TreeNode* b){
        if(root->val == a->val || root->val == b->val) return root;
        if(root->val < a->val && root->val < b->val) return lca(root->right, a, b);
        else if(root->val > a->val && root->val > b->val) return lca(root->left, a, b);
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return lca(root, p, q);
    }
};