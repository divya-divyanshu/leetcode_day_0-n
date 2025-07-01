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

    TreeNode* findrmst(TreeNode* root){
        if(root->right == nullptr) return root;
        return findrmst(root->right);
    }
    TreeNode* helper(TreeNode* root, int key){
        if(root->left == nullptr)  return root->right;
        if(root->right == nullptr) return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lstRightmost = findrmst(root->left);

        lstRightmost->right = rightChild;

        return root->left;
         
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root ==  nullptr) return nullptr;
        if(root->val == key)  return helper(root, key);


        TreeNode* dummy = root;
        while(root){
            if(root->val > key){
                if(root->left != nullptr && root->left->val == key) {
                    root->left = helper(root->left, key);
                    break;
                }
                else root = root->left;
            }
            else{
                if(root->right != nullptr && root->right->val == key) {
                    root->right = helper(root->right, key);
                    break;
                }
                else root = root->right;

            }
        }
        return dummy;
    }
};