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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        int ans =0;
        while(!q.empty()){
            int ind = q.front().second;
            int first, last;
            int sz = q.size();
            for(int i = 0; i< sz; i++){
                int cur_ind = q.front().second - ind;
                TreeNode* node = q.front().first;
                if(i == 0) first = cur_ind;
                if(i == sz-1) last = cur_ind;
                q.pop();

                if(node->left) q.push({node->left, 2LL*cur_ind+1});
                if(node->right)  q.push({node->right, 2LL*cur_ind+2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};