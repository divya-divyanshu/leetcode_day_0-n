class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
         priority_queue<int, vector<int>, greater<int>> hpx;

        for(int i = 0; i < nums.size(); i++){
            hpx.push(nums[i]);
            if(hpx.size() > k) hpx.pop();
        }
        return hpx.top();
    }
};