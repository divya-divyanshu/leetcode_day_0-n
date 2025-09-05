/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    int maxi = INT_MIN;
    int mini = INT_MAX;
    int findMax(Node *root) {
        // code here
        if(root == nullptr) return maxi;
        maxi = max(maxi, root->data);
        findMax(root->left);
        findMax(root->right);
        return maxi;
        
    }

    int findMin(Node *root) {
        
        // code here
        if(root == nullptr) return maxi;
        mini = min(mini, root->data);
        findMin(root->left);
        findMin(root->right);
        return mini;
    }
};