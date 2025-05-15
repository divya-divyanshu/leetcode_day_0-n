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
    int hgt(TreeNode* node){
        if(node == nullptr) return 0;
        return max((1+hgt(node->left)), (1+hgt(node->right)));
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int lh = hgt(root->left);
        int rh = hgt(root->right);
        if(abs(lh - rh) > 1) return false;
        bool leftC = isBalanced(root->left);
        bool rightC = isBalanced(root->right);

        if(!leftC || !rightC) return false;
        return true;
    }
};