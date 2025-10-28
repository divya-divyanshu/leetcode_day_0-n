class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int>preSum(n, 0);
        vector<int>postSum(n, 0);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            preSum[i] = sum;
        }
        sum=  0;
        for(int i = n-1; i >= 0; i--){
            sum += nums[i];
            postSum[i] = sum;
        }

        int cnt = 0;

        for(int  i = 0; i < n; i++){
            if(nums[i] == 0){
                if(preSum[i] == postSum[i]) cnt += 2;
                else if(abs(preSum[i] - postSum[i]) == 1) cnt += 1;
            }
        }

        return cnt;
    }
};