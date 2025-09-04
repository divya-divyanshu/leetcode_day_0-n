class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>>hpi;
        
        for(auto &it:arr) hpi.push(it);
        
        int sum = 0;
        while(true){
            if(hpi.size() == 1) return sum;
            
            int temp = hpi.top();
            hpi.pop();
            temp += hpi.top();
            hpi.pop();
            sum += temp;
            hpi.push(temp);
        }
        return sum;
        
    }
};