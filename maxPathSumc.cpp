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
    int hgt(TreeNode* root, int & maxSum){
        if(root == nullptr) return 0;
        int lsum = max(0, hgt(root->left, maxSum));
        int rsum = max(0, hgt(root->right, maxSum));
        maxSum = max(maxSum, lsum+rsum+root->val);
        return max(lsum, rsum)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum  = INT_MIN;
        hgt(root, maxSum);
        return maxSum;
    }
};