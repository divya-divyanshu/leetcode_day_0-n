class NumArray {
public:
    vector<int>seg;
    vector<int>arr;

    void build(int idx, int low, int high){
        if(low == high){
            seg[idx] = arr[low];
            return;
        }
        int mid = low + (high-low)/2;
        build(2*idx+1, low, mid);
        build(2*idx+2, mid+1, high);
        seg[idx] = (seg[2*idx+1] + seg[2*idx+2]);
    }
    NumArray(vector<int>& nums) {
        int n = nums.size();
        arr.resize(n);
        for(int i = 0; i < n; i++) arr[i] = nums[i];
        seg.resize(4*n);
        build(0, 0, n-1);
    }

    int query(int idx, int low, int high, int l, int r){
        if(l <= low && r >= high) return seg[idx];
        if(r < low || l > high) return 0;

        long long mid = low + (high-low)/2;

        long long left = query(2*idx+1, low, mid, l, r);
        long long right = query(2*idx+2, mid+1, high, l,  r);

        return (left+right);
    }

    void updateNew(int idx, int low, int high, int i, int nv){
        if(low == high){
            seg[idx] = nv;
            arr[i] = nv;
            return;
        }
        long long mid = low + (high-low)/2;

        if(i <= mid) updateNew(2*idx+1, low, mid, i, nv);
        else updateNew(2*idx+2, mid+1, high, i, nv);
        seg[idx] = seg[2*idx+1]+seg[2*idx+2]; 
    }
    
    void update(int idx, int val) {
        int n = arr.size();
        updateNew(0, 0, n-1, idx, val);
    }
        
    int sumRange(int left, int right) {
        int n = arr.size();
        return query(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */