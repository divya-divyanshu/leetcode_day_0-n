class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>>hpi;

        for(int i  = 0; i < nums.size(); i++) hpi.push(nums[i]);

        vector<int>ans;
        while(!hpi.empty()){
            ans.push_back(hpi.top());
            hpi.pop();
        }
        return ans;
    }
};