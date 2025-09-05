class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>hpi;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto it:nums){
            hpi.push(it);
            if(hpi.size() >k) hpi.pop();
        }
    }
    
    int add(int val) {
        hpi.push(val);
        if(hpi.size()>K) hpi.pop();
        return hpi.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */