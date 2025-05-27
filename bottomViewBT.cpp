class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        queue<pair<Node*,int>>q;
        q.push({root, 0});
        map<int, int>mpp;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* temp = it.first;
            int vertical = it.second;
            
            mpp[vertical] = temp->data;
            
            
            if(temp->left) q.push({temp->left, vertical-1});
            if(temp->right) q.push({temp->right, vertical+1});
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};