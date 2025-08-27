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
    TreeNode* fn(vector<int>&arr, int& i, int bound){
        if(i == arr.size() || arr[i] > bound) return nullptr;

        TreeNode* root = new TreeNode(arr[i]);
        i++;
        root->left = fn(arr, i, root->val); // left - current root is bound
        root->right = fn(arr, i, bound); // right - transfer bound
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return fn(preorder, i, INT_MAX);
    }
};