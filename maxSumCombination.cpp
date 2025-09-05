class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();
        vector<int>ans;
        set<pair<int, int>>st;
        priority_queue<pair<int, pair<int, int>>>hpx;
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        hpx.push({a.back()+b.back(), {n-1,n-1}});
        st.insert({n-1,n-1});
        
        while(k){
            auto it  = hpx.top();
            hpx.pop();
            int sum =   it.first;
            int i = it.second.first;
            int j = it.second.second;
            ans.push_back(sum);
            
            if(st.find({i-1, j}) == st.end()){
                st.insert({i-1, j});
                hpx.push({a[i-1]+b[j], {i-1, j}});
            }
            if(st.find({i, j-1}) == st.end()){
                st.insert({i, j-1});
                hpx.push({a[i]+b[j-1], {i, j-1}});
            }
            k--;
        }
        return ans;
    }
};