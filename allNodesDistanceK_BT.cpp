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
    vector<int> fn(TreeNode* root, TreeNode* target, int k, unordered_map<TreeNode* , TreeNode*>& mpp){
        unordered_map<TreeNode*, bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target] = true;
        int curlevel = 0;
        while(!q.empty()){
            int sz = q.size();
            if(curlevel++ == k) break;

            for(int i = 0; i < sz; i++){
                TreeNode* cur = q.front();
                q.pop();

                if(cur->left && !vis[cur->left]){
                    vis[cur->left] = true;
                    q.push(cur->left);
                }
                if(cur->right && !vis[cur->right]){
                    vis[cur->right] = true;
                    q.push(cur->right);
                }
                if(mpp[cur] && !vis[mpp[cur]]){
                    vis[mpp[cur]] = true;
                    q.push(mpp[cur]);
                }
            }
        }
        vector<int>res;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            res.push_back(temp->val);
        }
        return res;
    }
    void markParents(unordered_map<TreeNode* , TreeNode*>& mpp, TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left){
                mpp[cur->left] = cur;
                q.push(cur->left);
            }
            if(cur->right){
                mpp[cur->right] = cur;
                q.push(cur->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*>mpp;
        markParents(mpp, root);
        return fn(root, target, k, mpp);
    }
};