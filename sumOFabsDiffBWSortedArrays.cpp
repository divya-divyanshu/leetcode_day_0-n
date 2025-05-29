class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int  n = nums.size();
        vector<int>preSum(n, 0);
        vector<int>sufSum(n, 0);
        vector<int>res(n, 0);
        
        int sum = 0;
        for(int i = 0; i <n; i++) {
            sum += nums[i];
            preSum[i] = sum;
        }
        sum = 0;
        for(int i = n-1; i >=0; i--){
            sum += nums[i];
            sufSum[i] = sum;
        }

        res[0] = abs(preSum[n-1] - nums[0]*n);
        res[n-1] = (n-1)*nums[n-1] - preSum[n-2];

        for(int i = 1; i < n-1; i++){
            int next = (n-i-1);
            int prev = i;
            res[i] = (prev*nums[i])-(preSum[i-1]) + (sufSum[i+1] - next*nums[i]);
        }

        return res;
    }
};