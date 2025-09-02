class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n);
        unordered_map<int, int>mpp;
        priority_queue<int, vector<int>, greater<int>> hpx;
        for(int i  = 0; i < n; i++) {
            hpx.push(arr[i]);
        }
        int rank = 1;
        while(!hpx.empty()){
            int temp = hpx.top();
            hpx.pop();
            if(mpp.find(temp) == mpp.end()){
                 mpp[temp] = rank;
                 rank++;
            }
            
        }
        for(int i = 0; i <n; i++)   {
            ans[i] = mpp[arr[i]];
        }
        return ans;
    }
};