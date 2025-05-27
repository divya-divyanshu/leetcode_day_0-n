class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        map<int , int>mpp;
        queue<pair<Node*, int>>q;
        q.push({root, 0});
        
        while(!q.empty()){
            auto a = q.front();
            q.pop();
            Node* node = a.first;
            int vertical = a.second;
            
            if(mpp.find(vertical) == mpp.end()){
                mpp[vertical] = node->data;
            }
            
            if(node->left){
                q.push({node->left, vertical-1});
            }
            if(node->right){
                q.push({node->right, vertical+1});
            }
        }
        vector<int>ans;
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};