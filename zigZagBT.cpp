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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root == nullptr) return ans;
        q.push(root);
        
        bool leftToRight = true;
        while(!q.empty()){
            vector<int>temp;
            int  n = q.size();
            for(int i  = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(leftToRight){
                ans.push_back(temp);
                leftToRight = !leftToRight;
            }
            else{
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                leftToRight = !leftToRight;
            }
        }
        return ans;
    }
};