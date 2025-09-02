
class Solution {
  public:
  
  class node{
      public:
      int data, i, j;
      node(int _data, int _i, int _j){
          data = _data;
          i = _i;
          j = _j;
      }
  };
  class compare{
      public:
      bool operator()(node* a, node*b){
          return a->data > b->data;
      }
  };
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
        // code here
        priority_queue<node*, vector<node*>, compare>hpi;
        for(int i  =0; i < k; i++){
            node* temp = new node(arr[i][0], i, 0);
            hpi.push(temp);
        }
        
        vector<int>ans;
        while(!hpi.empty()){
            ans.push_back(hpi.top()->data);
            int i =  hpi.top()->i;
            int j =  hpi.top()->j;
            
            hpi.pop();
            
            if(j+1 < arr[i].size()){
                node* temp = new node(arr[i][j+1], i, j+1);
                hpi.push(temp);
            }
        }
        return ans;
    }
};