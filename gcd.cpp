class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small = INT_MAX, large =  INT_MIN;

        for (int i = 0;i < nums.size(); i++){
            small = min(small, nums[i]);
            large = max(large, nums[i]);
        }

        for (int i = small; i >=1;i--){
            if ((large % i ==0) && (small % i == 0)) return i;
        }

        return 1;

        
    }
};