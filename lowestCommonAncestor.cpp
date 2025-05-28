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
    TreeNode* lca(TreeNode* node, TreeNode* a, TreeNode* b){
        if(node ==  nullptr || node ==a || node == b)  return node;

        TreeNode* left = lca(node->left, a, b);
        TreeNode* right = lca(node->right, a, b);

        if(left == nullptr) return right;
        else if(right == nullptr) return left;
        return node; // both are not nullptr, so root is the lca
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = lca(root, p, q);
        return ans;
    }
};