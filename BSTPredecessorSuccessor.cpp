/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

Node* findPred(Node* root, int key){
    Node* pred = nullptr;
    while(root){
        if(key  > root->data){
            pred = root;
            root = root->right;
        }
        else if(root->data >= key){
            root = root->left;
        }
    }
    return pred;
}

Node* findSuc(Node* root, int key){
    Node* succ = nullptr;
    while(root){
        if(key  >= root->data){
            root = root->right;
        }
        else{
            succ = root;
            root = root->left;
        }
    }
    return succ;
}

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        
        return {findPred(root, key), findSuc(root, key)};
    }
};