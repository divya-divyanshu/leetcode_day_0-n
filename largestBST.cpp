/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class NodeVal{
  public:
  int maxNode, minNode, maxSize;
  NodeVal(int mini, int maxi, int maxS){
      maxNode = maxi;
      minNode = mini;
      maxSize = maxS;
  }
};

class Solution {
private:
  NodeVal helper(Node* root){
      if(!root) return NodeVal(INT_MAX, INT_MIN, 0);
 
  
      auto left = helper(root->left);
      auto right = helper(root->right);
      
      if(left.maxNode < root->data && root->data < right.minNode){
          return NodeVal(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize+right.maxSize+1);
      }
      
      return NodeVal(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
  }
      
  
public:
  
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        // Your code here
        return helper(root).maxSize;
        
    }
};