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
    TreeNode* fn(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir, map<int, int>&mpp){
        if(pl > pr || il > ir) return nullptr;

        TreeNode* root = new TreeNode(preorder[pl]);
        int inInd = mpp[root->val];
        int numsleft = mpp[root->val] - il;

        TreeNode* leftt = fn(preorder, pl+1, pl+numsleft, inorder,il, inInd-1, mpp);
        TreeNode* rightt = fn(preorder, pl+numsleft+1,pr, inorder, inInd+1, ir, mpp);

        root->left = leftt;
        root->right = rightt;

        return root;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int>mpp;
        for(int i  = 0; i < inorder.size(); i++) mpp[inorder[i]] = i;
        return fn(preorder,0, preorder.size()-1, inorder, 0, inorder.size()-1, mpp);
    }
};