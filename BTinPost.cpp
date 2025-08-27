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
    TreeNode* fn(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, map<int, int>&mpp){
        if(ps > pe || is > ie) return nullptr;
        TreeNode* root = new TreeNode(postorder[pe]);
        int rootInd = mpp[root->val];
        int numsleft = rootInd - is;
        root->left = fn(inorder, is, rootInd-1, postorder, ps, ps+numsleft-1, mpp);
        root->right = fn(inorder, rootInd+1, ie, postorder, ps+numsleft, pe-1, mpp);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int m = postorder.size();
        if(n != m) return nullptr;

        map<int, int>mpp;
        for(int i = 0; i <n; i++) mpp[inorder[i]] = i;

        return fn(inorder, 0, n-1, postorder, 0, m-1, mpp);
    }


};