class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum  = 0;

        // max sum
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if ( sum > maxi) maxi = sum;
            if ( sum < 0) sum = 0;
        }

        // min sum
        sum  = 0;
        int mini = INT_MAX;
        for (int i  = 0; i < nums.size(); i++){
            sum += nums[i];
            if ( sum < mini) mini = sum;
            if ( sum > 0) sum =0;
        }

        // total sum 

        int total_sum  = 0;
        for (int i = 0; i < nums.size(); i++){
            total_sum += nums[i];
        }

        if ( maxi < 0) return maxi;

        return max(maxi, total_sum-mini);

    }
};