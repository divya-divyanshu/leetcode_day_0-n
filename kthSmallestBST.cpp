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
    void fn(TreeNode* root, int &cnt, int k, int &ans){
        if(root == nullptr) return;
        fn(root->left, cnt, k, ans);
        cnt++;
        if(cnt == k)  {
            ans = root->val; 
            return;
        }
        fn(root->right, cnt, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt  = 0;
        int ans = 0;
        fn(root, cnt, k, ans);
        return ans;
    }
};