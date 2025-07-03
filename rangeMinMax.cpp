class Solution {
  public: 
    pair<int, int> query(int idx, int low, int high, int l, int r, vector<vector<int>>&seg){
        if(low >= l && high <= r) return make_pair(seg[idx][0], seg[idx][1]);
        if(r < low || l > high) return make_pair(INT_MAX, INT_MIN);
        
        int mid = low + (high-low)/2;
        
        auto a = query(2*idx+1, low, mid, l, r, seg);
        auto b = query(2*idx+2, mid+1, high, l, r, seg);
        
        return make_pair(min(a.first, b.first), max(a.second, b.second));
    }
    vector<int> getMinMax(vector<int>& arr, int L, int R,
                          vector<vector<int>>& seg) {
        int low = 0;
        int high = arr.size()-1;
        
        auto ans = query(0, low, high, L, R, seg);
        
        vector<int>anss;
        anss.push_back(ans.first);
        anss.push_back(ans.second);
        
        return anss;
                              
    }
    
    void update(int idx, vector<int>& arr, int low, int high, int i, int val,vector<vector<int>>& seg){
        if(low == high){
            arr[i] = val;
            seg[idx][0] =val;
            seg[idx][1] =val;
            return;
        }
        
        int mid = low +(high-low)/2;
        
        if(i <= mid) update(2*idx+1, arr, low, mid, i, val, seg);
        else if(i > mid && i <= high) update(2*idx+2, arr, mid+1, high, i, val, seg);
        
        seg[idx][0] = min(seg[2*idx+1][0], seg[2*idx+2][0]);
        seg[idx][1] = max(seg[2*idx+1][1], seg[2*idx+2][1]);
    }
 
    void updateValue(vector<int>& arr, int i, int val,
                     vector<vector<int>>& seg) {
        update(0, arr, 0, arr.size()-1, i, val, seg);
    }
};